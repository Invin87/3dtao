
#include "../gcode.h"
#include "../../core/serial.h"

/**
 * M118: Display a message in the host console.
 *
 *  A1  Prepend '// ' for an action command, as in OctoPrint
 *  E1  Have the host 'echo:' the text
 *  Pn  Redirect to another serial port
 *        0 : Announce to all ports
 *      1-9 : Serial ports 1 to 9
 */
void GcodeSuite::M118() {
  bool hasE = false, hasA = false;
  #if NUM_SERIAL > 1
    int8_t port = -1; // Assume no redirect
  #endif
  char *p = parser.string_arg;
  for (uint8_t i = 3; i--;) {
    // A1, E1, and Pn are always parsed out
    if (!( ((p[0] == 'A' || p[0] == 'E') && p[1] == '1') || (p[0] == 'P' && NUMERIC(p[1])) )) break;
    switch (p[0]) {
      case 'A': hasA = true; break;
      case 'E': hasE = true; break;
      #if NUM_SERIAL > 1
        case 'P': port = p[1] - '0'; break;
      #endif
    }
    p += 2;
    while (*p == ' ') ++p;
  }

  #if NUM_SERIAL > 1
    const int8_t old_serial = serial_port_index;
    if (WITHIN(port, 0, NUM_SERIAL))
      serial_port_index = (
        port == 0 ? SERIAL_BOTH
        : port == 1 ? SERIAL_PORT
        #ifdef SERIAL_PORT_2
          : port == 2 ? SERIAL_PORT_2
        #endif
        : SERIAL_PORT
      );
  #endif

  if (hasE) SERIAL_ECHO_START();
  if (hasA) SERIAL_ECHOPGM("// ");
  SERIAL_ECHOLN(p);

  #if NUM_SERIAL > 1
    serial_port_index = old_serial;
  #endif
}
