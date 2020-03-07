#pragma once

#include "pins_BTT_SKR_MINI_E3.h"

#define BOARD_INFO_NAME "BIGTREE SKR Mini E3 V1.2"

#define NEOPIXEL_PIN       PC7  // LED driving pin

/**
 * TMC2208/TMC2209 stepper drivers
 */
#if HAS_TMC220x
    // Software serial
    #define X_SERIAL_TX_PIN  PB15
  #define X_SERIAL_RX_PIN  PB15

  #define Y_SERIAL_TX_PIN  PC6
  #define Y_SERIAL_RX_PIN  PC6

  #define Z_SERIAL_TX_PIN  PC10
  #define Z_SERIAL_RX_PIN  PC10

  #define E0_SERIAL_TX_PIN PC11
  #define E0_SERIAL_RX_PIN PC11

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif
