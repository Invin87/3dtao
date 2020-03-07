#pragma once

/**
 * Arduino Mega with RAMPS v1.3 for Anycubic
 */

#define BOARD_INFO_NAME "Anycubic RAMPS 1.3"

#define IS_RAMPS_EFB
#define RAMPS_D9_PIN         44
#define FAN2_PIN              9
#define ORIG_E0_AUTO_FAN_PIN  9

#include "pins_RAMPS_13.h"

#undef E1_STEP_PIN
#undef E1_DIR_PIN
#undef E1_ENABLE_PIN
#undef E1_CS_PIN
