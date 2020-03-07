
#include "../gcode.h"
#include "../../module/temperature.h"

/**
 * M105: Read hot end and bed temperature
 */
void GcodeSuite::M105() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  SERIAL_ECHOPGM(STR_OK);

  #if HAS_TEMP_SENSOR

    thermalManager.print_heater_states(target_extruder
      #if ENABLED(TEMP_SENSOR_1_AS_REDUNDANT)
        , parser.boolval('R')
      #endif
    );

    SERIAL_EOL();

  #else

    SERIAL_ECHOLNPGM(" T:0"); // Some hosts send M105 to test the serial connection

  #endif
}
