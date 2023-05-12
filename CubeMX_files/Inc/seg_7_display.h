#pragma once

#ifndef NUCLEO_F446RE_SEG_7_DISPLAY_H
#define NUCLEO_F446RE_SEG_7_DISPLAY_H
#include <stdint.h>

void seg7_show(uint8_t value);
void seg_7_display_digit(uint8_t value);
void seg7_update(void);

#endif //NUCLEO_F446RE_SEG_7_DISPLAY_H
