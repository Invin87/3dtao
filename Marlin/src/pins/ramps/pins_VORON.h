#pragma once

/**
 * VORON Design v2 pin assignments
 * See https://github.com/mzbotreprap/VORON/blob/master/Firmware/Marlin/pins_RAMPS_VORON.h
 */

#define BOARD_INFO_NAME "VORON Design v2"

#define RAMPS_D8_PIN       11

#include "pins_RAMPS.h"

// Heaters / Fans
#undef FAN_PIN
#define FAN_PIN             5   // Using the pin for the controller fan since controller fan is always on.
#define CONTROLLER_FAN_PIN  8
#define ORIG_E0_AUTO_FAN_PIN 6  // Servo pin 6 for E3D Fan
#define ORIG_E1_AUTO_FAN_PIN 6  // Servo pin 6 for E3D Fan (same pin for both extruders since it's the same fan)

// LCDs and Controllers
#undef BEEPER_PIN
