
#include "../gcode.h"
#include "../queue.h" // for last_N

/**
 * M110: Set Current Line Number
 */
void GcodeSuite::M110() {
  if (parser.seenval('N')) queue.last_N = parser.value_long();
}
