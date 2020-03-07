#pragma once

// FYSETC F6 v1.4 pin assignments

#define BOARD_NAME "FYSETC F6 1.4"

#define Z_MAX_PIN           2

#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   */
  #define X_SERIAL_RX_PIN  72
  #define X_SERIAL_TX_PIN  71
  #define Y_SERIAL_RX_PIN  73
  #define Y_SERIAL_TX_PIN  78
  #define Z_SERIAL_RX_PIN  75
  #define Z_SERIAL_TX_PIN  79
  #define E0_SERIAL_RX_PIN 77
  #define E0_SERIAL_TX_PIN 81
  #define E1_SERIAL_RX_PIN 76
  #define E1_SERIAL_TX_PIN 80
  #define E2_SERIAL_RX_PIN 62
  #define E2_SERIAL_TX_PIN 82
#endif

#include "pins_FYSETC_F6_13.h"
