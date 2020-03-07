
#include "../../inc/MarlinConfig.h"

#if ENABLED(BAUD_RATE_GCODE)

#include "../gcode.h"

/**
 * M575 - Change serial baud rate
 *
 *   P<index>    - Serial port index. Omit for all.
 *   B<baudrate> - Baud rate (bits per second)
 */
void GcodeSuite::M575() {
  const int32_t baud = parser.ulongval('B');
  switch (baud) {
    case 2400: case 9600: case 19200: case 38400: case 57600:
    case 115200: case 250000: case 500000: case 1000000: {
      const int8_t port = parser.intval('P', -99);
      const bool set0 = (port == -99 || port == 0);
      if (set0) {
        SERIAL_ECHO_START();
        SERIAL_ECHOLNPAIR(" Serial "
          #if NUM_SERIAL > 1
            , '0',
          #else
            "0"
          #endif
          " baud rate set to ", baud
        );
      }
      #if NUM_SERIAL > 1
        const bool set1 = (port == -99 || port == 1);
        if (set1) {
          SERIAL_ECHO_START();
          SERIAL_ECHOLNPAIR(" Serial ", '1', " baud rate set to ", baud);
        }
      #endif

      SERIAL_FLUSH();

      if (set0) { MYSERIAL0.end(); MYSERIAL0.begin(baud); }

      #if NUM_SERIAL > 1
        if (set1) { MYSERIAL1.end(); MYSERIAL1.begin(baud); }
      #endif

    } break;
    default: SERIAL_ECHO_MSG("?(B)aud rate implausible.");
  }
}

#endif // NUM_SERIAL > 0 && BAUD_RATE_GCODE
