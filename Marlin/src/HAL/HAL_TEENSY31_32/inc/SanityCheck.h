#pragma once

/**
 * Test TEENSY35_36 specific configuration values for errors at compile-time.
 */

#if ENABLED(EMERGENCY_PARSER)
  #error "EMERGENCY_PARSER is not yet implemented for Teensy 3.1/3.2. Disable EMERGENCY_PARSER to continue."
#endif

#if ENABLED(FAST_PWM_FAN)
  #error "FAST_PWM_FAN is not yet implemented for this platform."
#endif

#if HAS_TMC_SW_SERIAL
  #error "TMC220x Software Serial is not supported on this platform."
#endif
