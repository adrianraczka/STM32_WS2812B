#include <stdint.h>
#include "math.h"
#include "stdio.h"
#include "rgb_hsl_hsv.h"

#define MAX(x,y) ((x > y) ? x : y)
#define MIN(x,y) ((x < y) ? x : y)

rgb hsv2rgb(float h, float s, float v) {
    rgb RGB;

    float C = s * v;
    float H_ = h / 60.0f;

    float X = C * (1 - fabs(fmod(H_, 2.0f) - 1));

    float r1=0, g1=0, b1=0;
    if(H_ >= 0 && H_ < 1) {
        r1 = C;
        g1 = X;
        b1 = 0;
    }
    else if (H_ >= 1 && H_ < 2) {
        r1 = X;
        g1 = C;
        b1 = 0;
    }
    else if (H_ >= 2 && H_ < 3) {
        r1 = 0;
        g1 = C;
        b1 = X;
    }
    else if (H_ >= 3 && H_ < 4) {
        r1 = 0;
        g1 = X;
        b1 = C;
    }
    else if (H_ >= 4 && H_ < 5) {
        r1 = X;
        g1 = 0;
        b1 = C;
    }
    else if (H_ >= 5 && H_ <= 6) {
        r1 = C;
        g1 = 0;
        b1 = X;
    }

    float m = v - C;

    RGB.r = r1 + m;
    RGB.g = g1 + m;
    RGB.b = b1 + m;

    return RGB;
}

rgb hsl2rgb(float h, float s, float l) {
    rgb RGB;

    float C = (float)(1.0f - fabs(2.0f * l - 1.0f)) * s;
    float H_ = h / 60.0f;

    float X = C * (float)(1 - fabs(fmod(H_, 2.0f) - 1));

    float r1=0, g1=0, b1=0;
    if(H_ >= 0 && H_ < 1) {
        r1 = C;
        g1 = X;
        b1 = 0;
    }
    else if (H_ >= 1 && H_ < 2) {
        r1 = X;
        g1 = C;
        b1 = 0;
    }
    else if (H_ >= 2 && H_ < 3) {
        r1 = 0;
        g1 = C;
        b1 = X;
    }
    else if (H_ >= 3 && H_ < 4) {
        r1 = 0;
        g1 = X;
        b1 = C;
    }
    else if (H_ >= 4 && H_ < 5) {
        r1 = X;
        g1 = 0;
        b1 = C;
    }
    else if (H_ >= 5 && H_ <= 6) {
        r1 = C;
        g1 = 0;
        b1 = X;
    }

    float m = l - (C/2);

    RGB.r = r1 + m;
    RGB.g = g1 + m;
    RGB.b = b1 + m;

    return RGB;
}