#pragma once

/**
 * Pin assignments for the MKS RUMBA32
 *
 * https://aus3d.com.au/rumba32
 * https://github.com/Aus3D/RUMBA32
 *
 * The MKS and Aus3D versions have the same pinout but the MKS version
 * has some added resistors and LEDs.  The resistors needed for the
 * TMC2208/9 UART interface are among the additions.  Also added were
 * connectors and resistors dedicated to the TMC2130 sensorless homing
 * interface.
 */

#define BOARD_INFO_NAME "Aus3D RUMBA32"

#define RUMBA32_V1_0
//#define I2C_EEPROM

#include "pins_RUMBA32_common.h"
