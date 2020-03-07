#pragma once

// Prefix header for all Marlin sources

#include "MarlinConfigPre.h"

#include "../HAL/HAL.h"

#include "../pins/pins.h"
#include HAL_PATH(../HAL, spi_pins.h)

#include "Conditionals_post.h"
#include HAL_PATH(../HAL, inc/Conditionals_post.h)

#include "SanityCheck.h"
#include HAL_PATH(../HAL, inc/SanityCheck.h)

// Include all core headers
#include "../core/types.h"
#include "../core/language.h"
#include "../core/utility.h"
#include "../core/serial.h"
