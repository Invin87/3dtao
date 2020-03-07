
#include "../../inc/MarlinConfig.h"

#if ENABLED(AUTO_REPORT_TEMPERATURES) && HAS_TEMP_SENSOR

#include "../gcode.h"
#include "../../module/temperature.h"

/**
 * M155: Set temperature auto-report interval. M155 S<seconds>
 */
void GcodeSuite::M155() {

  if (parser.seenval('S'))
    thermalManager.set_auto_report_interval(parser.value_byte());

}

#endif // AUTO_REPORT_TEMPERATURES && HAS_TEMP_SENSOR
