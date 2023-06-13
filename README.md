# STM32_WS2812B

This project was to create a WS2812B RGB controller using STM32F446RE MCU. Timers was used to communicate with WS2812B and to read data from TSOP1838T.

Used elements:
- STM32F446RE
- 74HC125
- TSOP1838T

Scheme:

![STM32_WS2812B](https://github.com/adrianraczka/STM32_WS2812B/assets/109549335/6410b8ed-9d3c-4c42-8169-114ad0921f71) 

This project consists of 4 modes:
1. steady
2. pulse
3. dynamic color change
4. snake

Modes can be switch between using remote.
