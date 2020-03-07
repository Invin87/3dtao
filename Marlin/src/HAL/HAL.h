#pragma once

#include "platforms.h"

#include HAL_PATH(.,HAL.h)

#define HAL_ADC_RANGE _BV(HAL_ADC_RESOLUTION)

inline void watchdog_refresh() {
  #if ENABLED(USE_WATCHDOG)
    HAL_watchdog_refresh();
  #endif
}
