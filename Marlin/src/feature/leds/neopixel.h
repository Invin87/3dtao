#pragma once

/**
 * Neopixel support
 */

// ------------------------
// Includes
// ------------------------

#include "../../inc/MarlinConfig.h"

#include <Adafruit_NeoPixel.h>
#include <stdint.h>

// ------------------------
// Defines
// ------------------------

#define MULTIPLE_NEOPIXEL_TYPES (defined(NEOPIXEL2_TYPE) && (NEOPIXEL2_TYPE != NEOPIXEL_TYPE))

#define NEOPIXEL_IS_RGB  (NEOPIXEL_TYPE == NEO_RGB || NEOPIXEL_TYPE == NEO_RBG || NEOPIXEL_TYPE == NEO_GRB || NEOPIXEL_TYPE == NEO_GBR || NEOPIXEL_TYPE == NEO_BRG || NEOPIXEL_TYPE == NEO_BGR)
#define NEOPIXEL_IS_RGBW !NEOPIXEL_IS_RGB

#if NEOPIXEL_IS_RGB
  #define NEO_WHITE 255, 255, 255, 0
#else
  #define NEO_WHITE 0, 0, 0, 255
#endif

// ------------------------
// Function prototypes
// ------------------------

class Marlin_NeoPixel {
private:
  static Adafruit_NeoPixel adaneo1
    #if MULTIPLE_NEOPIXEL_TYPES
      , adaneo2
    #endif
  ;

public:
  static void init();
  static void set_color_startup(const uint32_t c);

  static void set_color(const uint32_t c);

  #ifdef NEOPIXEL_BKGD_LED_INDEX
    static void set_color_background();
  #endif

  static inline void begin() {
    adaneo1.begin();
    #if MULTIPLE_NEOPIXEL_TYPES
      adaneo2.begin();
    #endif
  }

  static inline void set_pixel_color(const uint16_t n, const uint32_t c) {
    adaneo1.setPixelColor(n, c);
    #if MULTIPLE_NEOPIXEL_TYPES
      adaneo2.setPixelColor(n, c);
    #endif
  }

  static inline void set_brightness(const uint8_t b) {
    adaneo1.setBrightness(b);
    #if MULTIPLE_NEOPIXEL_TYPES
      adaneo2.setBrightness(b);
    #endif
  }

  static inline void show() {
    adaneo1.show();
    #if PIN_EXISTS(NEOPIXEL2)
      #if MULTIPLE_NEOPIXEL_TYPES
        adaneo2.show();
      #else
        adaneo1.setPin(NEOPIXEL2_PIN);
        adaneo1.show();
        adaneo1.setPin(NEOPIXEL_PIN);
      #endif
    #endif
  }

  #if 0
    bool set_led_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t w, const uint8_t p);
  #endif

  // Accessors
  static inline uint16_t pixels() { return adaneo1.numPixels(); }
  static inline uint8_t brightness() { return adaneo1.getBrightness(); }
  static inline uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    return adaneo1.Color(r, g, b, w);
  }
};

extern Marlin_NeoPixel neo;
