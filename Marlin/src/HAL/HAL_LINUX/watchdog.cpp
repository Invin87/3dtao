
#ifdef __PLAT_LINUX__

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

#include "watchdog.h"

void watchdog_init() {}
void HAL_watchdog_refresh() {}

#endif

#endif // __PLAT_LINUX__
