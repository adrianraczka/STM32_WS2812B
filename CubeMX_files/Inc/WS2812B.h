#pragma once

#ifndef NUCLEO_F446RE_WS2812B_H
#define NUCLEO_F446RE_WS2812B_H
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "stdbool.h"
#include "rgb_hsl_hsv.h"

struct Color {
    float h;
    float s;
    float v;
};

struct Mode {
    bool steady;
    bool pulse;
    bool dynamic_color_change;
    bool snake;
};

struct WS2812B{
    struct Mode mode;
    struct Color color;
    uint16_t leds_number;
    bool is_ON;
};

extern struct WS2812B LED;
extern uint16_t led_number;

void ws2812b_init(void);
void ws2812b_set_color(uint16_t led, float h, float s, float v);
void ws2812b_update(void);
void update_all_leds(float h, float s, float v);
void turn_off_all_leds(void);
void pulse(void);
void dynamic(void);
void snake(void);

#endif //NUCLEO_F446RE_WS2812B_H
