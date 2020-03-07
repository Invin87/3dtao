/************
 * compat.h *
 ************/

#pragma once

/**
 * This following provides compatibility whether compiling
 * as a part of Marlin or outside it
 */

#ifdef __has_include
  #if __has_include("../../ui_api.h")
    #include "../../ui_api.h"
  #endif
#else
  #include "../../ui_api.h"
#endif

#ifdef __MARLIN_FIRMWARE__
  // __MARLIN_FIRMWARE__ exists when compiled within Marlin.
  #include "pin_mappings.h"
  #undef max
  #define max(a,b) ((a)>(b)?(a):(b))
  #undef min
  #define min(a,b) ((a)<(b)?(a):(b))
#else
  namespace UI {
    static inline uint32_t safe_millis() {return millis();};
    static inline void     yield()       {};
  };
#endif

class __FlashStringHelper;
typedef const __FlashStringHelper *progmem_str;
