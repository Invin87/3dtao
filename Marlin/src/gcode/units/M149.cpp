
#include "../../inc/MarlinConfig.h"

#if ENABLED(TEMPERATURE_UNITS_SUPPORT)

#include "../gcode.h"

/**
 * M149: Set temperature units
 */
void GcodeSuite::M149() {
       if (parser.seenval('C')) parser.set_input_temp_units(TEMPUNIT_C);
  else if (parser.seenval('K')) parser.set_input_temp_units(TEMPUNIT_K);
  else if (parser.seenval('F')) parser.set_input_temp_units(TEMPUNIT_F);
}

#endif // TEMPERATURE_UNITS_SUPPORT
