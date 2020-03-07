
#include "../gcode.h"
#include "../../module/motion.h"

/**
 * M220: Set speed percentage factor, aka "Feed Rate"
 *
 * Parameters
 *   S<percent> : Set the feed rate percentage factor
 *
 * With PRUSA_MMU2...
 *   B : Flag to back up the current factor
 *   R : Flag to restore the last-saved factor
 */
void GcodeSuite::M220() {

  #if ENABLED(PRUSA_MMU2)
    static int16_t backup_feedrate_percentage = 100;
    if (parser.seen('B')) backup_feedrate_percentage = feedrate_percentage;
    if (parser.seen('R')) feedrate_percentage = backup_feedrate_percentage;
  #endif

  if (parser.seenval('S')) feedrate_percentage = parser.value_int();

}
