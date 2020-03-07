
#if defined(ARDUINO_ARCH_STM32) && !defined(STM32GENERIC)

#include "../../inc/MarlinConfigPre.h"

#if ENABLED(USE_WATCHDOG)

  #include "../../inc/MarlinConfig.h"

  #include "watchdog.h"
  #include <IWatchdog.h>

  void watchdog_init() { IWatchdog.begin(4000000); } // 4 sec timeout

  void HAL_watchdog_refresh() {
    IWatchdog.reload();
    #if DISABLED(PINS_DEBUGGING) && PIN_EXISTS(LED)
      TOGGLE(LED_PIN);  // heartbeat indicator
    #endif
  }

#endif // USE_WATCHDOG
#endif // ARDUINO_ARCH_STM32 && !STM32GENERIC
