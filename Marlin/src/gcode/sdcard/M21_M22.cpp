
#include "../../inc/MarlinConfig.h"

#if ENABLED(SDSUPPORT)

#include "../gcode.h"
#include "../../sd/cardreader.h"

/**
 * M21: Init SD Card
 */
void GcodeSuite::M21() { card.mount(); }

/**
 * M22: Release SD Card
 */
void GcodeSuite::M22() { card.release(); }

#endif // SDSUPPORT
