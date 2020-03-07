#pragma once

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Creality3D RAMPS supports only 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "Creality3D RAMPS"

// Heaters / Fans

// Power outputs EFBF or EFBE
#define MOSFET_D_PIN 7

#define FIL_RUNOUT_PIN 2
#if NUM_RUNOUT_SENSORS > 1
  #define FIL_RUNOUT2_PIN  15 // Creality CR-X can use dual runout sensors
#endif

#define SD_DETECT_PIN      49  // Always define onboard SD detect

#define PS_ON_PIN          40 // Used by CR2020 Industrial series

#if ENABLED(CASE_LIGHT_ENABLE) && !defined(CASE_LIGHT_PIN)
  #define CASE_LIGHT_PIN   65
#endif

#include "pins_RAMPS.h"

#ifndef BEEPER_PIN
  #define BEEPER_PIN       37  // Always define beeper pin so Play Tone works with ExtUI
#endif

#define EXP1_PIN           65   // A11 - Used by CR2020 Industrial series for case
#define EXP2_PIN           66   // A12
#define EXP3_PIN           11   // SERVO0_PIN
#define EXP4_PIN           12   // PS_ON_PIN

#define SUICIDE_PIN        12 // Used by CR2020 Industrial series
#define SUICIDE_PIN_INVERTING true // Used by CR2020 Industrial series
