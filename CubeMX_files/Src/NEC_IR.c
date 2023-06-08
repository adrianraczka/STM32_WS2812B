#include "stdio.h"
#include "string.h"
#include "usart.h"
#include "NEC_IR.h"
#include "tim.h"
#include "WS2812B.h"

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
    if (nec_command != nec__command || nec_address != nec__address) {
        //print error via UART
        HAL_UART_Transmit(&huart2, (uint8_t *)"NEC read error!\r\n", strlen("NEC read error!\r\n"), HAL_MAX_DELAY);
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

void ir_tim_interrupt(void) {
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

void ir_init(void) {
    HAL_TIM_Base_Start(&htim2);
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
}

int ir_read(void) {
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

void button_control(void) {
    int val = ir_read();
    char buff[25];
    switch (val) {
        //ON
        case IR_CODE_1x1:
            if(!LED.is_ON) {
                LED.is_ON = true;
                if(LED.mode.snake) {
                    for(uint16_t i=0; i < led_number; i++) {
                        ws2812b_set_color(i, LED.color.h, LED.color.s, 1.0f);
                        ws2812b_update();
                    }
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        //OFF
        case IR_CODE_1x2:
            if(LED.is_ON) {
                turn_off_all_leds();
                LED.is_ON = false;
            }
            break;
        //snake mode ON
        case IR_CODE_1x3:
            if(LED.is_ON && !LED.mode.snake) {
                LED.mode.steady = false;
                LED.mode.pulse = false;
                LED.mode.dynamic_color_change = false;
                LED.mode.snake = true;
                turn_off_all_leds();
                led_number = 0;
            }
            break;
        //steady mode ON
        case IR_CODE_2x1:
            if(LED.is_ON && !LED.mode.steady) {
                LED.mode.steady = true;
                LED.mode.pulse = false;
                LED.mode.dynamic_color_change = false;
                LED.mode.snake = false;
                update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        //pulse mode ON
        case IR_CODE_2x2:
            if(LED.is_ON && !LED.mode.pulse) {
                LED.mode.steady = false;
                LED.mode.pulse = true;
                LED.mode.dynamic_color_change = false;
                LED.mode.snake = false;
            }
            break;
        //dynamic color change mode ON
        case IR_CODE_2x3:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.mode.steady = false;
                LED.mode.pulse = false;
                LED.mode.dynamic_color_change = true;
                LED.mode.snake = false;
                update_all_leds(LED.color.h, 1.0f, LED.color.v);
            }
            break;
        //decreasing brightness
        case IR_CODE_3x1:
            if (LED.is_ON && !LED.mode.pulse && !LED.mode.snake) {
                if (LED.color.v > 0.02f) {
                    LED.color.v-=0.01f;
                    //if dynamic mode in ON - do not update color
                    if(LED.mode.dynamic_color_change) {
                        break;
                    }
                    update_all_leds(LED.color.h, LED.color.s, LED.color.v);
                }
            }
            break;
        //increasing brightness
        case IR_CODE_3x2:
            if (LED.is_ON && !LED.mode.pulse && !LED.mode.snake) {
                if (LED.color.v < 0.99f) {
                    LED.color.v+=0.01f;
                    //if dynamic mode in ON - do not update color
                    if(LED.mode.dynamic_color_change) break;
                    else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
                }
            }
            break;
        //steady and pulse modes colors
        case IR_CODE_3x3:
            if (LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.s = 0.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_4x1:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 0.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_4x2:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 30.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_4x3:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 60.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_5x1:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 90.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_5x2:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 120.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_5x3:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 150.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_6x1:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 180.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_6x2:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 210.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_6x3:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 240.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_7x1:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 270.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_7x2:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 300.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
            }
            break;
        case IR_CODE_7x3:
            if(LED.is_ON && !LED.mode.dynamic_color_change) {
                LED.color.h = 330.00f;
                LED.color.s = 1.00f;
                if(LED.mode.pulse || LED.mode.snake) {
                    if(LED.mode.snake) {
                        turn_off_all_leds();
                        led_number = 0;
                    }
                    break;
                }
                else update_all_leds(LED.color.h, LED.color.s, LED.color.v);
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