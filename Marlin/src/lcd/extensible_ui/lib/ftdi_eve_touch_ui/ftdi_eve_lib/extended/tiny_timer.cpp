/******************
 * tiny_timer.cpp *
 ******************/

#include "ftdi_extended.h"

#ifdef FTDI_EXTENDED

bool tiny_timer_t::elapsed(tiny_time_t duration) {
  uint8_t now = tiny_time_t::tiny_time(
    #ifdef __MARLIN_FIRMWARE__
      ExtUI::safe_millis()
    #else
      millis()
    #endif
  );
  uint8_t elapsed = now - _start;
  if (elapsed >= duration._duration) {
    return true;
  } else {
    return false;
  }
}

void tiny_timer_t::start() {
  _start = tiny_time_t::tiny_time(
    #ifdef __MARLIN_FIRMWARE__
      ExtUI::safe_millis()
    #else
      millis()
    #endif
  );
}
#endif // FTDI_EXTENDED
