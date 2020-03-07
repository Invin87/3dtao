#pragma once

#include "pins_BTT_SKR_MINI_E3.h"

#define BOARD_INFO_NAME "BIGTREE SKR Mini E3"

/**
 * TMC220x stepper drivers
 * Hardware serial communication ports.
 */
#if HAS_TMC_UART
  #define X_HARDWARE_SERIAL  Serial4
  #define Y_HARDWARE_SERIAL  Serial4
  #define Z_HARDWARE_SERIAL  Serial4
  #define E0_HARDWARE_SERIAL Serial4
#endif
