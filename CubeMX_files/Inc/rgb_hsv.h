#pragma once

#ifndef NUCLEO_F446RE_RGB_HSV_H
#define NUCLEO_F446RE_RGB_HSV_H
typedef struct {
    float r;       // ∈ [0, 1]
    float g;       // ∈ [0, 1]
    float b;       // ∈ [0, 1]
} rgb;

rgb hsv2rgb(float h, float s, float v);
rgb hsl2rgb(float h, float s, float l);
#endif //NUCLEO_F446RE_RGB_HSV_H
