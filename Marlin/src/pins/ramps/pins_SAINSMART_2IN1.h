#pragma once

/**
 * Sainsmart 2-in-1 pin assignments
 */

#if HOTENDS > 2 || E_STEPPERS > 2
  #error "Sainsmart 2-in-1 supports up to 2 hotends / E-steppers. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME "Sainsmart"

// Heaters / Fans
#define RAMPS_D10_PIN 9   // E
#define RAMPS_D9_PIN  7   // F PART FAN in front of board next to Extruder heat
     // RAMPS_D8_PIN  8   // B
#define MOSFET_D_PIN 10   // F / E

#include "pins_RAMPS.h"
