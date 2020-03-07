#pragma once

/**
 * Melzi pin assignments
 */

#define BOARD_INFO_NAME "Melzi (Tronxy)"
#include "pins_MELZI.h"

#undef Z_ENABLE_PIN
#undef LCD_PINS_RS
#undef LCD_PINS_ENABLE
#undef LCD_PINS_D4
#undef LCD_PINS_D5
#undef LCD_PINS_D6
#undef LCD_PINS_D7
#undef BTN_EN1
#undef BTN_EN2
#undef BTN_ENC
#undef LCD_SDSS

#define Z_ENABLE_PIN    14
#define LCD_PINS_RS     30
#define LCD_PINS_ENABLE 28
#define LCD_PINS_D4     16
#define LCD_PINS_D5     17
#define LCD_PINS_D6     27
#define LCD_PINS_D7     29
#define BTN_EN1         10
#define BTN_EN2         11
#define BTN_ENC         26

#if HAS_GRAPHICAL_LCD
  #define BOARD_ST7920_DELAY_1 DELAY_NS(0)
  #define BOARD_ST7920_DELAY_2 DELAY_NS(125)
  #define BOARD_ST7920_DELAY_3 DELAY_NS(0)
#endif
