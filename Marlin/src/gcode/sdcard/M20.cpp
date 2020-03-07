
#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../../sd/cardreader.h"

/**
 * M20: List SD card to serial output
 */
void GcodeSuite::M20() {
  SERIAL_ECHOLNPGM(STR_BEGIN_FILE_LIST);
  card.ls();
  SERIAL_ECHOLNPGM(STR_END_FILE_LIST);
}

#endif // SDSUPPORT
