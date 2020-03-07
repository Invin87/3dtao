#pragma once

/**
 * Geeetech A20M pin assignment
 */

#define LCD_PINS_RS       5
#define LCD_PINS_ENABLE  36
#define LCD_PINS_D4      21
#define LCD_PINS_D7       6

#if ENABLED(NEWPANEL)
  #define BTN_EN1        16
  #define BTN_EN2        17
  #define BTN_ENC        19
#endif

#include "pins_GT2560_V3.h"
