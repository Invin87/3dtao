
#include "../gcode.h"

/**
 * M111: Set the debug level
 */
void GcodeSuite::M111() {
  if (parser.seen('S')) marlin_debug_flags = parser.byteval('S');

  static const char str_debug_1[] PROGMEM = STR_DEBUG_ECHO,
                    str_debug_2[] PROGMEM = STR_DEBUG_INFO,
                    str_debug_4[] PROGMEM = STR_DEBUG_ERRORS,
                    str_debug_8[] PROGMEM = STR_DEBUG_DRYRUN,
                    str_debug_16[] PROGMEM = STR_DEBUG_COMMUNICATION
                    #if ENABLED(DEBUG_LEVELING_FEATURE)
                      , str_debug_lvl[] PROGMEM = STR_DEBUG_LEVELING
                    #endif
                    ;

  static PGM_P const debug_strings[] PROGMEM = {
    str_debug_1, str_debug_2, str_debug_4, str_debug_8, str_debug_16
    #if ENABLED(DEBUG_LEVELING_FEATURE)
      , str_debug_lvl
    #endif
  };

  SERIAL_ECHO_START();
  SERIAL_ECHOPGM(STR_DEBUG_PREFIX);
  if (marlin_debug_flags) {
    uint8_t comma = 0;
    for (uint8_t i = 0; i < COUNT(debug_strings); i++) {
      if (TEST(marlin_debug_flags, i)) {
        if (comma++) SERIAL_CHAR(',');
        serialprintPGM((char*)pgm_read_ptr(&debug_strings[i]));
      }
    }
  }
  else {
    SERIAL_ECHOPGM(STR_DEBUG_OFF);
    #if !defined(__AVR__) || !defined(USBCON)
      #if ENABLED(SERIAL_STATS_RX_BUFFER_OVERRUNS)
        SERIAL_ECHOPAIR("\nBuffer Overruns: ", MYSERIAL0.buffer_overruns());
      #endif

      #if ENABLED(SERIAL_STATS_RX_FRAMING_ERRORS)
        SERIAL_ECHOPAIR("\nFraming Errors: ", MYSERIAL0.framing_errors());
      #endif

      #if ENABLED(SERIAL_STATS_DROPPED_RX)
        SERIAL_ECHOPAIR("\nDropped bytes: ", MYSERIAL0.dropped());
      #endif

      #if ENABLED(SERIAL_STATS_MAX_RX_QUEUED)
        SERIAL_ECHOPAIR("\nMax RX Queue Size: ", MYSERIAL0.rxMaxEnqueued());
      #endif
    #endif //  !defined(__AVR__) || !defined(USBCON)
  }
  SERIAL_EOL();
}
