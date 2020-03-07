
#include "../gcode.h"
#include "../../module/planner.h"

#if EXTRUDERS

/**
 * M221: Set extrusion percentage (M221 T0 S95)
 */
void GcodeSuite::M221() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  if (parser.seenval('S')) {
    planner.flow_percentage[target_extruder] = parser.value_int();
    planner.refresh_e_factor(target_extruder);
  }
  else {
    SERIAL_ECHO_START();
    SERIAL_CHAR('E', '0' + target_extruder);
    SERIAL_ECHOPAIR(" Flow: ", planner.flow_percentage[target_extruder]);
    SERIAL_CHAR('%');
    SERIAL_EOL();
  }
}

#endif // EXTRUDERS
