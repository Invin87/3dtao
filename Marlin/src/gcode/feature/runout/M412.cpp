
#include "../../../inc/MarlinConfig.h"

#if HAS_FILAMENT_SENSOR

#include "../../gcode.h"
#include "../../../feature/runout.h"

/**
 * M412: Enable / Disable filament runout detection
 */
void GcodeSuite::M412() {
  if (parser.seen("RS"
    #ifdef FILAMENT_RUNOUT_DISTANCE_MM
      "D"
    #endif
    #if ENABLED(HOST_ACTION_COMMANDS)
      "H"
    #endif
  )) {
    #if ENABLED(HOST_ACTION_COMMANDS)
      if (parser.seen('H')) runout.host_handling = parser.value_bool();
    #endif
    const bool seenR = parser.seen('R'), seenS = parser.seen('S');
    if (seenR || seenS) runout.reset();
    if (seenS) runout.enabled = parser.value_bool();
    #ifdef FILAMENT_RUNOUT_DISTANCE_MM
      if (parser.seen('D')) runout.set_runout_distance(parser.value_linear_units());
    #endif
  }
  else {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM("Filament runout ");
    serialprintln_onoff(runout.enabled);
    #ifdef FILAMENT_RUNOUT_DISTANCE_MM
      SERIAL_ECHOLNPAIR("Filament runout distance (mm): ", runout.runout_distance());
    #endif
  }
}

#endif // HAS_FILAMENT_SENSOR
