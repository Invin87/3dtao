
#if defined(__MK64FX512__) || defined(__MK66FX1M0__)

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

#include "watchdog.h"

void watchdog_init() {
  WDOG_TOVALH = 0;
  WDOG_TOVALL = 4000;
  WDOG_STCTRLH = WDOG_STCTRLH_WDOGEN;
}

#endif // USE_WATCHDOG

#endif // __MK64FX512__ || __MK66FX1M0__
