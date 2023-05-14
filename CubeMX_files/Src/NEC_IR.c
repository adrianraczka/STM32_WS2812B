#include "stdio.h"
#include "string.h"
#include "usart.h"
#include "NEC_IR.h"
#include "tim.h"
#include "WS2812B.h"
#include "rgb_hsv.h"

typedef enum {
    PULSE_9MS,
    PULSE_4MS,
    PULSE_2MS,
    PULSE_LONG,
    PULSE_SHORT,
    PULSE_ERROR,
}pulse_t;

static volatile uint32_t received_value;
static int received_bits;

static bool check_data(void) {
    uint8_t nec_command = received_value >> 16;
    uint8_t nec__command = ~(received_value >> 24);

    uint8_t nec_address = received_value;
    uint8_t nec__address = ~(received_value >> 8);
    char buff[30];
    if (nec_command != nec__command || nec_address != nec__address) {
        //print error via UART
        sprintf(buff, "error!\r\n");
        HAL_UART_Transmit(&huart2, (uint8_t *) buff, strlen(buff), HAL_MAX_DELAY);
        //wrong data
        return false;
    }
    //data OK
    else return true;
}

static pulse_t calc_pulse(uint32_t time)
{
    if (time < 250)
        return PULSE_ERROR;
    else if (time < 1200)
        return PULSE_SHORT;
    else if (time < 2000)
        return PULSE_LONG;
    else if (time < 3000)
        return PULSE_2MS;
    else if (time < 6000)
        return PULSE_4MS;
    else if (time < 12000)
        return PULSE_9MS;
    else
        return PULSE_ERROR;
}

void ir_tim_interrupt(void)
{
    pulse_t pulse;

    if (received_bits >= 32)
        return;

    pulse = calc_pulse(HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1));

    switch (pulse) {
        case PULSE_SHORT:
            received_value = received_value >> 1;
            received_bits++;
            break;
        case PULSE_LONG:
            received_value = (received_value >> 1) | 0x80000000;
            received_bits++;
            break;
        case PULSE_4MS:
            received_value = 0;
            received_bits = 0;
            break;
        case PULSE_2MS:
            if (received_bits == 0) {
                received_bits = 32;
            }
            break;
        default:
            received_bits = 0;
            break;
    }
}

void ir_init(void)
{
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
}

int ir_read(void)
{
    if (received_bits != 32)
        return -1;
    if (!check_data()) {
        received_value = 0;
        received_bits = 0;
        return -1;
    }

    uint8_t value = received_value >> 16;
    received_bits = 0;

    return value;
}

rgb RGB;
void button_control(void) {
    int val = ir_read();
    char buff[25];
    switch (val) {
        //ON
        case IR_CODE_1x1:
            if(!LED.is_ON) {
                update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
                LED.is_ON = true;
            }
            break;
        //OFF
        case IR_CODE_1x2:
            if(LED.is_ON) {
                update_all_leds(0, 0, 0);
                LED.is_ON = false;
            }
            break;
        //
        case IR_CODE_1x3:
            break;
        //
        case IR_CODE_2x1:
            break;
        //
        case IR_CODE_2x2:
            break;
        //
        case IR_CODE_2x3:
            break;
        //
        case IR_CODE_3x1:
            if (LED.is_ON && LED.mode.steady) {
                if (LED.color.red > 5 + 1) {
                    LED.color.red-=5;
                }
                if (LED.color.green > 5 + 1) {
                    LED.color.green-=5;
                }
                if (LED.color.blue > 5 + 1) {
                    LED.color.blue-=5;
                }
            }
            update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            break;
        //
        case IR_CODE_3x2:
            if (LED.is_ON && LED.mode.steady) {
                if (LED.color.red < 255- 5 && LED.color.red != 0) {
                    LED.color.red+=5;
                }
                if (LED.color.green < 255 - 5 && LED.color.green != 0) {
                    LED.color.green+=5;
                }
                if (LED.color.blue < 255 - 5 && LED.color.blue != 0) {
                    LED.color.blue+=5;
                }
            }
            update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            break;
        //
        case IR_CODE_3x3:
            break;
        //RED
        case IR_CODE_4x1:
            if(LED.is_ON && LED.mode.steady) {
                LED.color.red = 128;
                LED.color.green = 0;
                LED.color.blue = 0;
                update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            }
            break;
        //GREEN
        case IR_CODE_4x2:
            if(LED.is_ON && LED.mode.steady) {
                LED.color.red = 0;
                LED.color.green = 128;
                LED.color.blue = 0;
                update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            }
            break;
        //BLUE
        case IR_CODE_4x3:
            if(LED.is_ON && LED.mode.steady) {
                LED.color.red = 0;
                LED.color.green = 0;
                LED.color.blue = 128;
                update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            }
            break;
        //WHITE
        case IR_CODE_5x1:
            if(LED.is_ON && LED.mode.steady) {
                LED.color.red = 128;
                LED.color.green = 128;
                LED.color.blue = 128;
                update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
            }
            break;
        default:
            break;
    }
    if (val != -1) {
        sprintf(buff, "%02x\r\n", val);
        HAL_UART_Transmit(&huart2, (uint8_t *) buff, strlen(buff), HAL_MAX_DELAY);
    }
}

void update_all_leds(uint8_t r, uint8_t g, uint8_t b) {
    for(int i=0; i < LED.leds_number; i++) {
        ws2812b_set_color(i, r, g, b);
        ws2812b_update();
    }
}

void move(void) {
    static double temp;
    if(temp < 360) {
        RGB = hsl2rgb(temp+=0.1, 1.0, 0.01);
        LED.color.red = (uint8_t)(RGB.r * 255.0f);
        LED.color.green = (uint8_t)(RGB.g * 255.0f);
        LED.color.blue = (uint8_t)(RGB.b * 255.0f);
        update_all_leds(LED.color.red, LED.color.green, LED.color.blue);
    }
}