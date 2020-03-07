#pragma once

/**
 * HAL/shared/Marduino.h
 */

#undef DISABLED       // Redefined by ESP32
#undef M_PI           // Redefined by all
#undef _BV            // Redefined by some
#undef sq             // Redefined by teensy3/wiring.h
#undef SBI            // Redefined by arduino/const_functions.h
#undef CBI            // Redefined by arduino/const_functions.h
#undef UNUSED         // Redefined by stm32f4xx_hal_def.h

#include <Arduino.h>  // NOTE: If included earlier then this line is a NOOP

#undef DISABLED
#define DISABLED(V...) DO(DIS,&&,V)

#undef _BV
#define _BV(b) (1UL << (b))

#undef sq
#define sq(x) ((x)*(x))

#ifndef SBI
  #define SBI(A,B) (A |= (1 << (B)))
#endif

#ifndef CBI
  #define CBI(A,B) (A &= ~(1 << (B)))
#endif

#ifndef __AVR__
  #ifndef strchr_P // Some platforms define a macro (DUE, teensy35)
    inline const char* strchr_P(const char *s, int c) { return strchr(s,c); }
    //#define strchr_P(s,c) strchr(s,c)
  #endif

  #ifndef snprintf_P
    #define snprintf_P snprintf
  #endif
  #ifndef vsnprintf_P
    #define vsnprintf_P vsnprintf
  #endif
#endif

// Restart causes
#define RST_POWER_ON    1
#define RST_EXTERNAL    2
#define RST_BROWN_OUT   4
#define RST_WATCHDOG    8
#define RST_JTAG       16
#define RST_SOFTWARE   32
#define RST_BACKUP     64

#ifndef M_PI
  #define M_PI 3.14159265358979323846f
#endif

// Remove compiler warning on an unused variable
#ifndef UNUSED
  #define UNUSED(x) ((void)(x))
#endif
