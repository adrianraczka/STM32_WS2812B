#include "WS2812B.h"
#include "math.h"
#include "float.h"

#define BIT_0_TIME		32
#define BIT_1_TIME		64

#define RESET_LEN		40
#define LED_N			9

struct WS2812B LED = {.mode.steady = true, .mode.pulse = false, .mode.dynamic_color_change = false, .mode.snake = false, .color.h = 0.00f, .color.s = 0.00f, .color.v = 0.01f, .leds_number = 9, .is_ON = true};

static uint16_t led_buffer[RESET_LEN + 24 * LED_N];

static void set_byte(uint32_t pos, uint8_t value) {
    int i;
    for (i = 0; i < 8; i++) {
        if (value & 0x80) {
            led_buffer[pos + i] = BIT_1_TIME;
        } else {
            led_buffer[pos + i] = BIT_0_TIME;
        }

        value <<= 1;
    }
}

void ws2812b_init(void) {
    uint8_t i;
    for (i = 0; i < RESET_LEN; i++)
        led_buffer[i] = 0;

    for (i = 0; i < 24 * LED_N; i++)
        led_buffer[RESET_LEN + i] = BIT_0_TIME;

    for(i=0; i < 9; i++) {
        ws2812b_set_color(i, LED.color.h, LED.color.s, LED.color.v);
    }

    HAL_TIM_Base_Start(&htim3);
    ws2812b_update();
}

void ws2812b_update(void) {
    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)led_buffer, sizeof(led_buffer));
}

void ws2812b_wait(void) {
    while (HAL_TIM_GetChannelState(&htim3, TIM_CHANNEL_1) == HAL_TIM_CHANNEL_STATE_BUSY) {}
}

void ws2812b_set_color(uint16_t led, float h, float s, float l) {
    rgb RGB = hsv2rgb(h, s, l);

    if (led < LED_N) {
        set_byte(RESET_LEN + 24 * led, (uint8_t)round(RGB.g*255.00));
        set_byte(RESET_LEN + 24 * led + 8, (uint8_t)round(RGB.r*255.00));
        set_byte(RESET_LEN + 24 * led + 16, (uint8_t)round(RGB.b*255.00));
    }
}

void update_all_leds(float h, float s, float l) {
    for(int i=0; i < LED.leds_number; i++) {
        ws2812b_set_color(i, h, s, l);
        ws2812b_update();
    }
}

bool pulse_increment = true;
void pulse(void) {
    static uint8_t iteration;
    static double x;
    //rescaler - 2
    if(iteration >= 2) {
        //overflow
        if(x == DBL_MAX) {
            x = asin(sin(DBL_MAX));
        }
        x += 0.01;
        update_all_leds(LED.color.h, LED.color.s, 0.5f * (1.0f + sinf((-3.1415f/2.0f) - (2 * x))));
        iteration = 0;
    }
        iteration++;
}

void dynamic(void) {
    static uint8_t iteration;
    static double x;
    //rescaler - 2
    if(iteration >= 2) {
        //overflow
        if(x == DBL_MAX) {
            x = acos(cos(DBL_MAX));
        }
        update_all_leds(180.0f * (1.0f + sinf(x += 0.01)), 1, LED.color.v);
        iteration = 0;
    }
    iteration++;
}