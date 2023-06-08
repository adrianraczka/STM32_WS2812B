#include "WS2812B.h"
#include "math.h"
#include "float.h"

#define BIT_0_TIME		32
#define BIT_1_TIME		64

#define RESET_LEN		40
//number of LED - user defined
#define LED_N           9
//starting values of LED
struct WS2812B LED = {.mode.steady = true, .mode.pulse = false, .mode.dynamic_color_change = false, .mode.snake = false, .color.h = 0.00f, .color.s = 0.00f, .color.v = 0.01f, .leds_number = LED_N, .is_ON = true};

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
static void LED_check(void) {
    turn_off_all_leds();
    for (uint16_t i = 0; i < LED.leds_number; i++) {
        if (i != 0) {
            ws2812b_set_color(i - 1, LED.color.h, LED.color.s, 0.00f);
            ws2812b_update();
        }
        ws2812b_set_color(i, LED.color.h, LED.color.s, 0.50f);
        ws2812b_update();
        HAL_Delay(150);
    }

    for (uint16_t i = LED.leds_number; i > 0; i--) {
        if (i != LED.leds_number) {
            ws2812b_set_color(i + 1, LED.color.h, LED.color.s, 0.00f);
            ws2812b_update();
        }
        ws2812b_set_color(i, LED.color.h, LED.color.s, 0.50f);
        ws2812b_update();
        HAL_Delay(150);
    }
    turn_off_all_leds();
}

void ws2812b_init(void) {
    uint8_t i;
    for (i = 0; i < RESET_LEN; i++) led_buffer[i] = 0;

    for (i = 0; i < 24 * LED.leds_number; i++) led_buffer[RESET_LEN + i] = BIT_0_TIME;

    HAL_TIM_Base_Start(&htim3);
    LED_check();

    for(uint16_t j = 0; j < LED.leds_number; j++) {
        ws2812b_set_color(j, LED.color.h, LED.color.s, LED.color.v);
    }
    ws2812b_update();
}

void ws2812b_update(void) {
    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)led_buffer, sizeof(led_buffer));
}

void ws2812b_set_color(uint16_t led, float h, float s, float v) {
    rgb RGB = hsv2rgb(h, s, v);

    if (led < LED.leds_number) {
        set_byte(RESET_LEN + 24 * led, (uint8_t)round(RGB.g*255.00));
        set_byte(RESET_LEN + 24 * led + 8, (uint8_t)round(RGB.r*255.00));
        set_byte(RESET_LEN + 24 * led + 16, (uint8_t)round(RGB.b*255.00));
    }
}

void update_all_leds(float h, float s, float v) {
    for(int i=0; i < LED.leds_number; i++) {
        ws2812b_set_color(i, h, s, v);
    }
    ws2812b_update();
}

void turn_off_all_leds(void) {
    for(int i=0; i < LED.leds_number; i++) {
        ws2812b_set_color(i, LED.color.h, LED.color.s, 0);
    }
    ws2812b_update();
}

void pulse(void) {
    static double x;
    //overflow
    if(x == DBL_MAX) {
        x = asin(sin(DBL_MAX));
    }
    update_all_leds(LED.color.h, LED.color.s, 0.5f * (1.0f + sinf((-3.1415f/2.0f) - (2*(x+=0.005)))));
}

void dynamic(void) {
    static double x;
    //overflow
    if(x == DBL_MAX) {
        x = acos(cos(DBL_MAX));
    }
    update_all_leds(180.0f * (1.0f + sinf(x += 0.005f)), 1.0f, LED.color.v);
}

uint16_t led_number;
void snake(void) {
    static float v;
    static bool increase = true;

    if(v >= 0.95f && increase) {
        led_number++;
        v = 0.00f;
    }
    else if(v <= 0.00f && !increase) {
        led_number--;
        v = 0.95f;
    }
    else {
        if(increase) ws2812b_set_color(led_number, LED.color.h, LED.color.s, v+=0.05f);
        else if(!increase) ws2812b_set_color(led_number, LED.color.h, LED.color.s, v-=0.05f);
        ws2812b_update();
    }
    if((led_number == LED.leds_number && increase && v >= 0.95f) || (led_number == 0 && !increase && v <= 0.00f)) {
        increase = !increase;
    }
}