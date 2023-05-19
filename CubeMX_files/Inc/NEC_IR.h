#pragma once

#ifndef NUCLEO_F446RE_NEC_IR_H
#define NUCLEO_F446RE_NEC_IR_H

#include "stm32f4xx_hal.h"

// Stałe opisujące klawisze
#define IR_CODE_1x1         0x45
#define IR_CODE_1x2         0x46
#define IR_CODE_1x3         0x47
#define IR_CODE_2x1         0x44
#define IR_CODE_2x2         0x40
#define IR_CODE_2x3         0x43
#define IR_CODE_3x1         0x07
#define IR_CODE_3x2         0x15
#define IR_CODE_3x3         0x09
#define IR_CODE_4x1         0x16
#define IR_CODE_4x2         0x19
#define IR_CODE_4x3         0x0d
#define IR_CODE_5x1         0x0c
#define IR_CODE_5x2         0x18
#define IR_CODE_5x3         0x5e
#define IR_CODE_6x1         0x08
#define IR_CODE_6x2         0x1c
#define IR_CODE_6x3         0x5a
#define IR_CODE_7x1         0x42
#define IR_CODE_7x2         0x52
#define IR_CODE_7x3         0x4a



// Procedura obsługi przerwania
void ir_tim_interrupt(void);

// Inicjalizacja modułu
void ir_init(void);

// Funkcja odczytująca dane
// return - kod klawisza lub -1
int ir_read(void);



void button_control(void);
void move(void);
#endif //NUCLEO_F446RE_NEC_IR_H
