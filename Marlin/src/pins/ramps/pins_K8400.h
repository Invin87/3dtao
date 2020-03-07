#pragma once

/**
 * Velleman K8400 (Vertex)
 * 3DRAG clone
 *
 * K8400 has some minor differences over a normal 3Drag:
 *  - No X/Y max endstops
 *  - Second extruder step pin has moved
 *  - No power supply control
 *  - Second heater has moved pin
 */

#define BOARD_INFO_NAME         "K8400"
#define DEFAULT_MACHINE_NAME    "Vertex"

#include "pins_3DRAG.h"

// Limit Switches
#define X_STOP_PIN  3
#define Y_STOP_PIN 14

#undef X_MIN_PIN
#undef X_MAX_PIN
#undef Y_MIN_PIN
#undef Y_MAX_PIN

// Steppers
#undef E1_STEP_PIN
#define E1_STEP_PIN 32

// Heaters / Fans
#undef HEATER_1_PIN
#define HEATER_1_PIN 11

// Misc. Functions
#undef PS_ON_PIN
#undef KILL_PIN
#undef SD_DETECT_PIN

#if Z_STEP_PIN == 26
  #undef Z_STEP_PIN
  #define Z_STEP_PIN 32
#endif
