#pragma once

/**
 * Test X86_64-specific configuration values for errors at compile-time.
 */

// Emulating RAMPS
#if ENABLED(SPINDLE_LASER_PWM) && !(SPINDLE_LASER_PWM_PIN == 4 || SPINDLE_LASER_PWM_PIN == 6 || SPINDLE_LASER_PWM_PIN == 11)
  #error "SPINDLE_LASER_PWM_PIN must use SERVO0, SERVO1 or SERVO3 connector"
#endif

#if ENABLED(FAST_PWM_FAN)
  #error "FAST_PWM_FAN is not yet implemented for this platform."
#endif

#if HAS_TMC_SW_SERIAL
  #error "TMC220x Software Serial is not supported on this platform."
#endif
