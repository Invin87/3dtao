#pragma once

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Dagoma3D F5 RAMPS supports only 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "Dagoma3D F5 RAMPS"

#define X_STOP_PIN          2
#define Y_STOP_PIN          3
#define Z_STOP_PIN         15
#define FIL_RUNOUT_PIN     39

#define ORIG_E0_AUTO_FAN_PIN 7

// Import RAMPS 1.4 pins
#include "pins_RAMPS.h"
