/*
 * ws2812.h
 */

#ifndef WS2812_H_
#define WS2812_H_

/* Max number of pixels supported by the library */
#define MAX_PIXELS (200)

typedef enum {
	ws2812_success,
	ws2812_error,
	ws2812_invalid_LED_id,
	ws2182_too_many_pixels,
}ws2812_rtn_t;

ws2812_rtn_t 	ws2812_init(uint16_t numPixels, cyhal_gpio_t mosi, cyhal_gpio_t miso, cyhal_gpio_t sclk);
ws2812_rtn_t 	ws2812_setRGB(uint16_t led, uint8_t red, uint8_t green, uint8_t blue);
ws2812_rtn_t 	ws2812_setMultiRGB(uint16_t startLED, uint16_t endLED, uint8_t red, uint8_t green, uint8_t blue);
ws2812_rtn_t	ws2812_update(void);

#endif /* WS2812_H_ */
