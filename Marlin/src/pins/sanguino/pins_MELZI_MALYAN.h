#pragma once

/**
 * Melzi (Malyan M150) pin assignments
 */

#define BOARD_INFO_NAME "Melzi (Malyan)"
#include "pins_MELZI.h"

#undef LCD_SDSS
#undef LCD_PINS_RS
#undef LCD_PINS_ENABLE
#undef LCD_PINS_D4
#undef BTN_EN1
#undef BTN_EN2
#undef BTN_ENC

#define LCD_PINS_RS        17   // ST9720 CS
#define LCD_PINS_ENABLE    16   // ST9720 DAT
#define LCD_PINS_D4        11   // ST9720 CLK
#define BTN_EN1            30
#define BTN_EN2            29
#define BTN_ENC            28

// Alter timing for graphical display
#if HAS_GRAPHICAL_LCD
  #define BOARD_ST7920_DELAY_1 DELAY_NS(125)
  #define BOARD_ST7920_DELAY_2 DELAY_NS(125)
  #define BOARD_ST7920_DELAY_3 DELAY_NS(125)
#endif
