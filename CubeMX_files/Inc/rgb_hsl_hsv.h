#pragma once

typedef struct {
    float r;       //[0, 1]
    float g;       //[0, 1]
    float b;       //[0, 1]
} rgb;

rgb hsv2rgb(float h, float s, float v);
rgb hsl2rgb(float h, float s, float l);