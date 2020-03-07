#pragma once

/**
 * Test AVR-specific configuration values for errors at compile-time.
 */

/**
 * Digipot requirement
 */
 #if ENABLED(DIGIPOT_MCP4018)
  #if !defined(DIGIPOTS_I2C_SDA_X) || !defined(DIGIPOTS_I2C_SDA_Y) || !defined(DIGIPOTS_I2C_SDA_Z) \
    || !defined(DIGIPOTS_I2C_SDA_E0) || !defined(DIGIPOTS_I2C_SDA_E1)
      #error "DIGIPOT_MCP4018 requires DIGIPOTS_I2C_SDA_* pins to be defined."
  #endif
#endif

/**
 * Checks for FAST PWM
 */
#if ENABLED(FAST_PWM_FAN) && (ENABLED(USE_OCR2A_AS_TOP) && defined(TCCR2))
  #error "USE_OCR2A_AS_TOP does not apply to devices with a single output TIMER2"
#endif

/**
 * Sanity checks for Spindle / Laser PWM
 */
#if ENABLED(SPINDLE_LASER_PWM)
  #if SPINDLE_LASER_PWM_PIN == 4 || WITHIN(SPINDLE_LASER_PWM_PIN, 11, 13)
    #error "Counter/Timer for SPINDLE_LASER_PWM_PIN is used by a system interrupt."
  #elif NUM_SERVOS > 0 && (WITHIN(SPINDLE_LASER_PWM_PIN, 2, 3) || SPINDLE_LASER_PWM_PIN == 5)
    #error "Counter/Timer for SPINDLE_LASER_PWM_PIN is used by the servo system."
  #endif
#endif

/**
 * The Trinamic library includes SoftwareSerial.h, leading to a compile error.
 */
#if HAS_TRINAMIC && ENABLED(ENDSTOP_INTERRUPTS_FEATURE)
  #error "TMCStepper includes SoftwareSerial.h which is incompatible with ENDSTOP_INTERRUPTS_FEATURE. Disable ENDSTOP_INTERRUPTS_FEATURE to continue."
#endif

#if HAS_TMC_SW_SERIAL && ENABLED(MONITOR_DRIVER_STATUS)
  #error "MONITOR_DRIVER_STATUS causes performance issues when used with SoftwareSerial-connected drivers. Disable MONITOR_DRIVER_STATUS or use hardware serial to continue."
#endif
