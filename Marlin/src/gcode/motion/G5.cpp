
#include "../../inc/MarlinConfig.h"

#if ENABLED(BEZIER_CURVE_SUPPORT)

#include "../../module/motion.h"
#include "../../module/planner_bezier.h"

/**
 * Parameters interpreted according to:
 * http://linuxcnc.org/docs/2.6/html/gcode/parser.html#sec:G5-Cubic-Spline
 * However I, J omission is not supported at this point; all
 * parameters can be omitted and default to zero.
 */

#include "../gcode.h"
#include "../../MarlinCore.h" // for IsRunning()

/**
 * G5: Cubic B-spline
 */
void GcodeSuite::G5() {
  if (MOTION_CONDITIONS) {

    #if ENABLED(CNC_WORKSPACE_PLANES)
      if (workspace_plane != PLANE_XY) {
        SERIAL_ERROR_MSG(STR_ERR_BAD_PLANE_MODE);
        return;
      }
    #endif

    get_destination_from_command();

    const xy_pos_t offsets[2] = {
      { parser.linearval('I'), parser.linearval('J') },
      { parser.linearval('P'), parser.linearval('Q') }
    };

    cubic_b_spline(current_position, destination, offsets, MMS_SCALED(feedrate_mm_s), active_extruder);
    current_position = destination;
  }
}

#endif // BEZIER_CURVE_SUPPORT
