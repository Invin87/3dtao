
/**
 * HAL for stm32duino.com based on Libmaple and compatible (STM32F1)
 */

#ifdef __STM32F1__

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

#include <libmaple/iwdg.h>
#include "watchdog.h"

void HAL_watchdog_refresh() {
  #if DISABLED(PINS_DEBUGGING) && PIN_EXISTS(LED)
    TOGGLE(LED_PIN);  // heartbeat indicator
  #endif
  iwdg_feed();
}

void watchdogSetup() {
  // do whatever. don't remove this function.
}

/**
 * @brief  Initialized the independent hardware watchdog.
 *
 * @return No return
 *
 * @details The watchdog clock is 40Khz. We need a 4 seconds interval, so use a /256 preescaler and 625 reload value (counts down to 0)
 */
void watchdog_init() {
  //iwdg_init(IWDG_PRE_256, STM32F1_WD_RELOAD);
}

#endif // USE_WATCHDOG
#endif // __STM32F1__
