#pragma once

/**
 * E4d@Box  pin assignments
 * E4d@Box is a small factor 3D printer control board based on the ESP32 microcontroller for Laser, CNC and 3d printers
 * for more info check http://atbox.tech/ and join to Facebook page E4d@box.
 */

#ifndef ARDUINO_ARCH_ESP32
  #error "Oops! Select an ESP32 board in 'Tools > Board.'"
#elif EXTRUDERS > 1 || E_STEPPERS > 1
  #error "E4d@box only supports one E Stepper. Comment out this line to continue."
#elif HOTENDS > 2
  #error "E4d@box currently supports only one hotend. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME       "E4D@BOX"
#define BOARD_WEBSITE_URL     "github.com/Exilaus/E4d@box"
#define DEFAULT_MACHINE_NAME  BOARD_INFO_NAME

// Limit Switches
#define X_MIN_PIN          34
#define Y_MIN_PIN          35
#define Z_MIN_PIN          16   // 15

// Steppers
#define X_STEP_PIN         12   // 34//27
#define X_DIR_PIN          13   // 35//26
#define X_ENABLE_PIN       17   // 0//17//25 // used free pin
//#define X_CS_PIN            0

#define Y_STEP_PIN         32   // 33
#define Y_DIR_PIN          33   // 32
#define Y_ENABLE_PIN       X_ENABLE_PIN
//#define Y_CS_PIN           13

#define Z_STEP_PIN         25   // 14
#define Z_DIR_PIN          26   // 12
#define Z_ENABLE_PIN       X_ENABLE_PIN
//#define Z_CS_PIN            5   // SS_PIN

#define E0_STEP_PIN        27   // 16
#define E0_DIR_PIN         14   // 17
#define E0_ENABLE_PIN      X_ENABLE_PIN
//#define E0_CS_PIN          21

// Temperature Sensors
#define TEMP_0_PIN         36   // Analog Input
#define TEMP_BED_PIN       39   // Analog Input

// Heaters / Fans
#define HEATER_0_PIN        2   // 4//2//(D8)
#define FAN_PIN             0   // 2//15//13 (D9)
#define HEATER_BED_PIN     15   // 15//0 //(D10)

// SPI
#define SDSS                 5
#define I2S_STEPPER_STREAM
#define I2S_WS              23
#define I2S_BCK             22
#define I2S_DATA            21
