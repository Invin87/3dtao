
#include "../gcode.h"

#if ENABLED(PLATFORM_M997_SUPPORT)

/**
 * M997: Perform in-application firmware update
 */
void GcodeSuite::M997() {
  flashFirmware(parser.intval('S'));
}

#endif
