#pragma once

/**
 * HAL for stm32duino.com based on Libmaple and compatible (STM32F1)
 */

#include <libmaple/iwdg.h>

/**
 *  The watchdog clock is 40Khz. We need a 4 seconds interval, so use a /256 preescaler and
 *  625 reload value (counts down to 0)
 *  use 1250 for 8 seconds
 */
#define STM32F1_WD_RELOAD 625

// Arduino STM32F1 core now has watchdog support

// Initialize watchdog with a 4 second countdown time
void watchdog_init();

// Reset watchdog. MUST be called at least every 4 seconds after the
// first watchdog_init or STM32F1 will reset.
void HAL_watchdog_refresh();
