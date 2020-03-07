
#ifdef ARDUINO_ARCH_ESP32

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

#include "watchdog.h"

void watchdogSetup() {
  // do whatever. don't remove this function.
}

void watchdog_init() {
  // TODO
}

#endif // USE_WATCHDOG

#endif // ARDUINO_ARCH_ESP32
