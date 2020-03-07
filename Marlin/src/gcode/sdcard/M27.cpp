
#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../../sd/cardreader.h"

/**
 * M27: Get SD Card status
 *      OR, with 'S<seconds>' set the SD status auto-report interval. (Requires AUTO_REPORT_SD_STATUS)
 *      OR, with 'C' get the current filename.
 */
void GcodeSuite::M27() {
  if (parser.seen('C')) {
    SERIAL_ECHOPGM("Current file: ");
    card.printFilename();
  }

  #if ENABLED(AUTO_REPORT_SD_STATUS)
    else if (parser.seenval('S'))
      card.set_auto_report_interval(parser.value_byte());
  #endif

  else
    card.report_status();
}

#endif // SDSUPPORT
