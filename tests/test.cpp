#include "catch2/catch_all.hpp"

extern "C" {
#include "rgb_hsl_hsv.h"
}

#define CATCH_CONFIG_NO_POSIX_SIGNALS

SCENARIO("hsv2rgb_test") {
    rgb RGB;
    //hsv
    //h = 0
    RGB = hsv2rgb(0.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(0.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(0.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 30
    RGB = hsv2rgb(30.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(30.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 191); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(30.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 96); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 60
    RGB = hsv2rgb(60.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(60.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(60.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 90
    RGB = hsv2rgb(90.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(90.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 191); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(90.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 96); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 120
    RGB = hsv2rgb(120.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 0); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(120.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(120.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 150
    RGB = hsv2rgb(150.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 0); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(150.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 191);

    RGB = hsv2rgb(150.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 96);

    //h = 180
    RGB = hsv2rgb(180.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 0); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(180.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(180.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    //h = 210
    RGB = hsv2rgb(210.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 0); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(210.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 191); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(210.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 96); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    //h = 240
    RGB = hsv2rgb(240.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 0); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(240.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(240.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    //h = 270
    RGB = hsv2rgb(270.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(270.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 191); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(270.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 96); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    //h = 300
    RGB = hsv2rgb(300.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(300.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsv2rgb(300.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    //h = 330
    RGB = hsv2rgb(330.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(330.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 191);

    RGB = hsv2rgb(330.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 96);

    //h = 360
    RGB = hsv2rgb(360.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 0); CHECK((uint8_t)round(RGB.b*255.0) == 0);

    RGB = hsv2rgb(360.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 128); CHECK((uint8_t)round(RGB.b*255.0) == 128);

    RGB = hsv2rgb(360.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 128); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 64);
}

SCENARIO("hsl2rgb_test") {
    rgb RGB;
    //hsl
    //h = 0
    RGB = hsl2rgb(0.0, 1.0, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsl2rgb(0.0, 0.5, 1.0);
    CHECK((uint8_t)round(RGB.r*255.0) == 255); CHECK((uint8_t)round(RGB.g*255.0) == 255); CHECK((uint8_t)round(RGB.b*255.0) == 255);

    RGB = hsl2rgb(0.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 191); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 75
    RGB = hsl2rgb(75.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 159); CHECK((uint8_t)round(RGB.g*255.0) == 191); CHECK((uint8_t)round(RGB.b*255.0) == 64);

    //h = 180
    RGB = hsl2rgb(180.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 64); CHECK((uint8_t)round(RGB.g*255.0) == 191); CHECK((uint8_t)round(RGB.b*255.0) == 191);

    //h = 275
    RGB = hsl2rgb(275.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 138); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 191);

    //h = 360
    RGB = hsl2rgb(360.0, 0.5, 0.5);
    CHECK((uint8_t)round(RGB.r*255.0) == 191); CHECK((uint8_t)round(RGB.g*255.0) == 64); CHECK((uint8_t)round(RGB.b*255.0) == 64);
}

