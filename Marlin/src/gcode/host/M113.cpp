
#include "../../inc/MarlinConfig.h"

#if ENABLED(HOST_KEEPALIVE_FEATURE)

#include "../gcode.h"

/**
 * M113: Get or set Host Keepalive interval (0 to disable)
 *
 *   S<seconds> Optional. Set the keepalive interval.
 */
void GcodeSuite::M113() {
  if (parser.seenval('S')) {
    host_keepalive_interval = parser.value_byte();
    NOMORE(host_keepalive_interval, 60);
  }
  else {
    SERIAL_ECHO_START();
    SERIAL_ECHOLNPAIR("M113 S", (unsigned long)host_keepalive_interval);
  }
}

#endif // HOST_KEEPALIVE_FEATURE
