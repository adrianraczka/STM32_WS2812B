#pragma once

#ifndef NUCLEO_F446RE_WS2812B_H
#define NUCLEO_F446RE_WS2812B_H
#include "stm32f4xx_hal.h"
#include "tim.h"

void ws2812b_init(void);

void ws2812b_set_color(uint16_t led, uint8_t red, uint8_t green, uint8_t blue);

void ws2812b_update(void);

void ws2812b_wait(void);

#endif //NUCLEO_F446RE_WS2812B_H
