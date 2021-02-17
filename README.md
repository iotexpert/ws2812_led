# WS2812 LED strip library for use with PSoC® 6

This is a driver library to interface with WS2812 LED strips using a PSOC 6. It uses SPI to drive the LEDs.

## Quick Start

To use the library:

1. Include the header file *ws2812.h*.

2. Call *ws2812_init* to initialize the library. The user specifies the the number of LEDs (pixels) and the SPI pins (MOSI, MISO, SCLK).

        ws2812_rtn_t 	ws2812_init(uint16_t numPixels, cyhal_gpio_t mosi, cyhal_gpio_t miso, cyhal_gpio_t sclk);

    - Setting the Clock divider parameter to NULL will auto-assign a clock with the appropriate speed.

3. Call *ws2812_setRGB* to set the color of one LED or call *ws2812_setMultiRGB* to set a range of LEDs to the same color.

        ws2812_rtn_t 	ws2812_setRGB(uint16_t led, uint8_t red, uint8_t green, uint8_t blue);

        ws2812_rtn_t 	ws2812_setMultiRGB(uint16_t startLED, uint16_t endLED, uint8_t red, uint8_t green, uint8_t blue);

4. Call *ws2812_update* to send a new set of colors to the LED strip.

        ws2812_rtn_t ws2812_update(void);

**Example Code**

The folowing code will initialize the library for a strip of 10 LEDs and will then set all LEDs to a series of colors.

    #include "ws2812.h"

    ws2812_init( 10, CYBSP_SPI_MOSI, CYBSP_SPI_MISO, CYBSP_SPI_CLK, NULL);

    for (;;)
    {
        ws2812_setMultiRGB( 0, 9, 255, 0, 0); // Set all LEDs to RED at max brighness
        ws2812_update();
        Cy_SysLib_Delay(100);
        ws2812_setMultiRGB( 0, 9, 0, 255, 0); // Set all LEDs to GREEN at max brighness
        ws2812_update();
        Cy_SysLib_Delay(100);
        ws2812_setMultiRGB( 0, 9, 0, 0, 255); // Set all LEDs to BLUE at max brighness
        ws2812_update();
        Cy_SysLib_Delay(100);
    }
