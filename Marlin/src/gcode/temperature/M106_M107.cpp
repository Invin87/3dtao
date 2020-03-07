
#include "../../inc/MarlinConfig.h"

#if FAN_COUNT > 0

#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/temperature.h"

#if ENABLED(SINGLENOZZLE)
  #define _ALT_P active_extruder
  #define _CNT_P EXTRUDERS
#else
  #define _ALT_P _MIN(active_extruder, FAN_COUNT - 1)
  #define _CNT_P FAN_COUNT
#endif

/**
 * M106: Set Fan Speed
 *
 *  S<int>   Speed between 0-255
 *  P<index> Fan index, if more than one fan
 *
 * With EXTRA_FAN_SPEED enabled:
 *
 *  T<int>   Restore/Use/Set Temporary Speed:
 *           1     = Restore previous speed after T2
 *           2     = Use temporary speed set with T3-255
 *           3-255 = Set the speed for use with T2
 */
void GcodeSuite::M106() {
  const uint8_t p = parser.byteval('P', _ALT_P);

  if (p < _CNT_P) {

    #if ENABLED(EXTRA_FAN_SPEED)
      const uint16_t t = parser.intval('T');
      if (t > 0) return thermalManager.set_temp_fan_speed(p, t);
    #endif
    uint16_t d = parser.seen('A') ? thermalManager.fan_speed[active_extruder] : 255;
    uint16_t s = parser.ushortval('S', d);
    NOMORE(s, 255U);

    thermalManager.set_fan_speed(p, s);
  }
}

/**
 * M107: Fan Off
 */
void GcodeSuite::M107() {
  const uint8_t p = parser.byteval('P', _ALT_P);
  thermalManager.set_fan_speed(p, 0);
}

#endif // FAN_COUNT > 0
