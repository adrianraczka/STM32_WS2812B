#pragma once

#ifndef NUCLEO_F446RE_WS2812B_H
#define NUCLEO_F446RE_WS2812B_H
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "stdbool.h"

struct Color {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

struct Mode {
    bool steady;
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

void ws2812b_init(void);
void ws2812b_init2(void);
void ws2812b_set_color(uint16_t led, uint8_t red, uint8_t green, uint8_t blue);
void ws2812b_update(void);
void ws2812b_wait(void);

#endif //NUCLEO_F446RE_WS2812B_H
