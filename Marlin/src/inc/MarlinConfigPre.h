#pragma once

#ifndef __MARLIN_FIRMWARE__
#define __MARLIN_FIRMWARE__
#endif

// Prefix header to acquire configurations
#include <stdint.h>

#include "../HAL/platforms.h"

#include "../core/boards.h"
#include "../core/macros.h"
#include "../../Configuration.h"

#ifdef CUSTOM_VERSION_FILE
  #if defined(__has_include)
    #if __has_include(XSTR(../../CUSTOM_VERSION_FILE))
      #include XSTR(../../CUSTOM_VERSION_FILE)
    #endif
  #else
    #include XSTR(../../CUSTOM_VERSION_FILE)
  #endif
#endif

#include "Version.h"

#include "Conditionals_LCD.h"
#include HAL_PATH(../HAL, inc/Conditionals_LCD.h)

#include "../core/drivers.h"
#include "../../Configuration_adv.h"

#include "Conditionals_adv.h"
#include HAL_PATH(../HAL, inc/Conditionals_adv.h)
