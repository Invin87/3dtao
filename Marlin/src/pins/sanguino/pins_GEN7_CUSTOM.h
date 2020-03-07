#pragma once

/**
 * Gen7 Alfons3 board pin assignments
 *
 * These Pins are assigned for the modified GEN7 Board from Alfons3.
 * Please review the pins and adjust them for your needs.
 */

/**
 * Rev B    26 DEC 2016
 *
 * 1) added pointer to a current Arduino IDE extension
 * 2) added support for M3, M4 & M5 spindle control commands
 * 3) added case light pin definition
 *
 */

/**
 * A useable Arduino IDE extension (board manager) can be found at
 * https://github.com/Lauszus/Sanguino
 *
 * This extension has been tested on Arduino 1.6.12 & 1.8.0
 *
 * Here's the JSON path:
 * https://raw.githubusercontent.com/Lauszus/Sanguino/master/package_lauszus_sanguino_index.json
 *
 * When installing select 1.0.2
 *
 * Installation instructions can be found at https://learn.sparkfun.com/pages/CustomBoardsArduino
 * Just use the above JSON URL instead of Sparkfun's JSON.
 *
 * Once installed select the Sanguino board and then select the CPU.
 *
 */

#if !defined(__AVR_ATmega644P__) && !defined(__AVR_ATmega644__) && !defined(__AVR_ATmega1284P__)
  #error "Oops! Select 'Sanguino' in 'Tools > Boards' and 'ATmega644', 'ATmega644P', or 'ATmega1284P' in 'Tools > Processor.'"
#endif

#define BOARD_INFO_NAME "Gen7 Custom"

// Limit Switches
#define X_STOP_PIN          0
#define Y_STOP_PIN          1
#define Z_STOP_PIN          2

// Steppers
#define X_STEP_PIN         21   // different from standard GEN7
#define X_DIR_PIN          20   // different from standard GEN7
#define X_ENABLE_PIN       24

#define Y_STEP_PIN         23
#define Y_DIR_PIN          22
#define Y_ENABLE_PIN       24

#define Z_STEP_PIN         26
#define Z_DIR_PIN          25
#define Z_ENABLE_PIN       24

#define E0_STEP_PIN        28
#define E0_DIR_PIN         27
#define E0_ENABLE_PIN      24

// Temperature Sensors
#define TEMP_0_PIN          2   // Analog Input
#define TEMP_BED_PIN        1   // Analog Input (pin 34 bed)

// Heaters
#define HEATER_0_PIN        4
#define HEATER_BED_PIN      3   // (bed)

// Misc. Functions
#define SDSS               31   // SCL pin of I2C header || CS Pin for SD Card support
#define PS_ON_PIN          19
#define CASE_LIGHT_PIN     15   // Hardware PWM

// A pin for debugging
#define DEBUG_PIN          -1

// LCD / Controller
#define BEEPER_PIN         -1

// 4bit LCD Support
#define LCD_PINS_RS        18
#define LCD_PINS_ENABLE    17
#define LCD_PINS_D4        16
#define LCD_PINS_D5        15
#define LCD_PINS_D6        13
#define LCD_PINS_D7        14

// Buttons are directly    attached
#define BTN_EN1            11
#define BTN_EN2            10
#define BTN_ENC            12

// RS485 pins
//#define TX_ENABLE_PIN   12
//#define RX_ENABLE_PIN   13

// M3/M4/M5 - Spindle/Laser Control
#define SPINDLE_LASER_ENA_PIN     5   // Pullup or pulldown!
#define SPINDLE_LASER_PWM_PIN    16   // Hardware PWM
#define SPINDLE_DIR_PIN           6
