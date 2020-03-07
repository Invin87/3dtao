
#include "../../inc/MarlinConfig.h"

#if HOTENDS && HAS_LCD_MENU

#include "../gcode.h"
#include "../../lcd/ultralcd.h"

/**
 * M145: Set the heatup state for a material in the LCD menu
 *
 *   S<material>
 *   H<hotend temp>
 *   B<bed temp>
 *   F<fan speed>
 */
void GcodeSuite::M145() {
  const uint8_t material = (uint8_t)parser.intval('S');
  if (material >= COUNT(ui.preheat_hotend_temp))
    SERIAL_ERROR_MSG(STR_ERR_MATERIAL_INDEX);
  else {
    int v;
    if (parser.seenval('H')) {
      v = parser.value_int();
      ui.preheat_hotend_temp[material] = constrain(v, EXTRUDE_MINTEMP, HEATER_0_MAXTEMP - 15);
    }
    if (parser.seenval('F')) {
      v = parser.value_int();
      ui.preheat_fan_speed[material] = (uint8_t)constrain(v, 0, 255);
    }
    #if TEMP_SENSOR_BED != 0
      if (parser.seenval('B')) {
        v = parser.value_int();
        ui.preheat_bed_temp[material] = constrain(v, BED_MINTEMP, BED_MAXTEMP - 10);
      }
    #endif
  }
}

#endif // HOTENDS && HAS_LCD_MENU
