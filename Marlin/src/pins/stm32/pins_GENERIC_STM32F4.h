#pragma once

/**
 * To build with Arduino IDE use "Discovery F407VG"
 * To build with PlatformIO use environment "STM32F4"
 */
#if !defined(STM32F4) && !defined(STM32F4xx)
  #error "Oops! Select an STM32F4 board in 'Tools > Board.'"
#elif HOTENDS > 2 || E_STEPPERS > 2
  #error "STM32F4 supports up to 2 hotends / E-steppers."
#endif

#define BOARD_INFO_NAME      "Misc. STM32F4"
#define DEFAULT_MACHINE_NAME "STM32F407VET6"

//#define I2C_EEPROM

#ifndef E2END
  #define E2END 0xFFF // 4KB
#endif

// Ignore temp readings during development.
//#define BOGUS_TEMPERATURE_GRACE_PERIOD 2000

// Limit Switches
#define X_MIN_PIN          PE0
#define X_MAX_PIN          -1
#define Y_MIN_PIN          PE1
#define Y_MAX_PIN          -1
#define Z_MIN_PIN          PE14
#define Z_MAX_PIN          -1

// Z Probe (when not Z_MIN_PIN)

//#ifndef Z_MIN_PROBE_PIN
//  #define Z_MIN_PROBE_PIN  PA4
//#endif

// Steppers

#define X_STEP_PIN         PD3
#define X_DIR_PIN          PD2
#define X_ENABLE_PIN       PD0
//#ifndef X_CS_PIN
//  #define X_CS_PIN         PD1
//#endif

#define Y_STEP_PIN         PE11
#define Y_DIR_PIN          PE10
#define Y_ENABLE_PIN       PE13
//#ifndef Y_CS_PIN
//  #define Y_CS_PIN         PE12
//#endif

#define Z_STEP_PIN         PD6
#define Z_DIR_PIN          PD7
#define Z_ENABLE_PIN       PD4
//#ifndef Z_CS_PIN
//  #define Z_CS_PIN         PD5
//#endif

#define E0_STEP_PIN        PB5
#define E0_DIR_PIN         PB6
#define E0_ENABLE_PIN      PB3
//#ifndef E0_CS_PIN
//  #define E0_CS_PIN         PB4
//#endif

#define E1_STEP_PIN        PE4
#define E1_DIR_PIN         PE2
#define E1_ENABLE_PIN      PE3
//#ifndef E1_CS_PIN
//  #define E1_CS_PIN         PE5
//#endif

#define SCK_PIN            PA5
#define MISO_PIN           PA6
#define MOSI_PIN           PA7

// Temperature Sensors

#define TEMP_0_PIN         PC0   // Analog Input
#define TEMP_1_PIN         PC1   // Analog Input
#define TEMP_BED_PIN       PC2   // Analog Input

// Heaters / Fans

#define HEATER_0_PIN       PA1
#define HEATER_1_PIN       PA2
#define HEATER_BED_PIN     PA0

#ifndef FAN_PIN
  #define FAN_PIN          PC6
#endif
#define FAN1_PIN           PC7
#define FAN2_PIN           PC8

#define ORIG_E0_AUTO_FAN_PIN  FAN1_PIN // Use this by NOT overriding E0_AUTO_FAN_PIN

// Misc. Functions

//#define CASE_LIGHT_PIN_CI PF13
//#define CASE_LIGHT_PIN_DO PF14
//#define NEOPIXEL_PIN      PF13

// Průša i3 MK2 Multi Material Multiplexer Support

//#define E_MUX0_PIN         PG3
//#define E_MUX1_PIN         PG4

// Servos

//#define SERVO0_PIN         PE13
//#define SERVO1_PIN         PE14


#define SDSS               PE7
#define SS_PIN             PE7
#define LED_PIN            PB7         //Alive
#define PS_ON_PIN          PA10
#define KILL_PIN           PA8
#define PWR_LOSS           PA4         //Power loss / nAC_FAULT

// LCD / Controller

#define SD_DETECT_PIN      PA15
#define BEEPER_PIN         PC9
#define LCD_PINS_RS        PE9
#define LCD_PINS_ENABLE    PE8
#define LCD_PINS_D4        PB12
#define LCD_PINS_D5        PB13
#define LCD_PINS_D6        PB14
#define LCD_PINS_D7        PB15
#define BTN_EN1            PC4
#define BTN_EN2            PC5
#define BTN_ENC            PC3

// Filament runout

#define FIL_RUNOUT_PIN     PA3

// ST7920 Delays
#if HAS_GRAPHICAL_LCD
  #define BOARD_ST7920_DELAY_1 DELAY_NS(96)
  #define BOARD_ST7920_DELAY_2 DELAY_NS(48)
  #define BOARD_ST7920_DELAY_3 DELAY_NS(715)
#endif