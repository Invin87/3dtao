#pragma once

/**
 * Test STM32F1-specific configuration values for errors at compile-time.
 */

#if ENABLED(EMERGENCY_PARSER)
  #error "EMERGENCY_PARSER is not yet implemented for STM32F1. Disable EMERGENCY_PARSER to continue."
#endif

#if ENABLED(SDIO_SUPPORT) && DISABLED(SDSUPPORT)
  #error "SDIO_SUPPORT requires SDSUPPORT. Enable SDSUPPORT to continue."
#endif

#if ENABLED(FAST_PWM_FAN)
  #error "FAST_PWM_FAN is not yet implemented for this platform."
#endif

#if !defined(HAVE_SW_SERIAL) && HAS_TMC_SW_SERIAL
  #warning "With TMC2208/9 consider using SoftwareSerialM with HAVE_SW_SERIAL and appropriate SS_TIMER."
  #error "Missing SoftwareSerial implementation."
#endif
