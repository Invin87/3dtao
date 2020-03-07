
#include "../../inc/MarlinConfig.h"

#if HAS_HOTEND_OFFSET

#include "../gcode.h"
#include "../../module/motion.h"

#if ENABLED(DELTA)
  #include "../../module/planner.h"
#endif

/**
 * M218 - set hotend offset (in linear units)
 *
 *   T<tool>
 *   X<xoffset>
 *   Y<yoffset>
 *   Z<zoffset>
 */
void GcodeSuite::M218() {

  const int8_t target_extruder = get_target_extruder_from_command();
  if (target_extruder < 0) return;

  if (parser.seenval('X')) hotend_offset[target_extruder].x = parser.value_linear_units();
  if (parser.seenval('Y')) hotend_offset[target_extruder].y = parser.value_linear_units();
  if (parser.seenval('Z')) hotend_offset[target_extruder].z = parser.value_linear_units();

  if (!parser.seen("XYZ")) {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM(STR_HOTEND_OFFSET);
    HOTEND_LOOP() {
      SERIAL_CHAR(' ');
      SERIAL_ECHO(hotend_offset[e].x);
      SERIAL_CHAR(',');
      SERIAL_ECHO(hotend_offset[e].y);
      SERIAL_CHAR(',');
      SERIAL_ECHO_F(hotend_offset[e].z, 3);
    }
    SERIAL_EOL();
  }

  #if ENABLED(DELTA)
    if (target_extruder == active_extruder)
      do_blocking_move_to_xy(current_position, planner.settings.max_feedrate_mm_s[X_AXIS]);
  #endif
}

#endif // HAS_HOTEND_OFFSET
