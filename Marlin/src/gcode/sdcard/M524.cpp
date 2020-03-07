
#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../../sd/cardreader.h"

/**
 * M524: Abort the current SD print job (started with M24)
 */
void GcodeSuite::M524() {

  if (IS_SD_PRINTING())
    card.flag.abort_sd_printing = true;

}

#endif // SDSUPPORT
