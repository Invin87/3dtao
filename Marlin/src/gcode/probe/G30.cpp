
#include "../../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/probe.h"
#include "../../feature/bedlevel/bedlevel.h"

/**
 * G30: Do a single Z probe at the current XY
 *
 * Parameters:
 *
 *   X   Probe X position (default current X)
 *   Y   Probe Y position (default current Y)
 *   E   Engage the probe for each probe (default 1)
 */
void GcodeSuite::G30() {

  const xy_pos_t pos = { parser.linearval('X', current_position.x + probe.offset_xy.x),
                         parser.linearval('Y', current_position.y + probe.offset_xy.y) };

  if (!position_is_reachable_by_probe(pos)) return;

  // Disable leveling so the planner won't mess with us
  #if HAS_LEVELING
    set_bed_leveling_enabled(false);
  #endif

  remember_feedrate_scaling_off();

  const ProbePtRaise raise_after = parser.boolval('E', true) ? PROBE_PT_STOW : PROBE_PT_NONE;
  const float measured_z = probe.probe_at_point(pos, raise_after, 1);
  if (!isnan(measured_z))
    SERIAL_ECHOLNPAIR("Bed X: ", FIXFLOAT(pos.x), " Y: ", FIXFLOAT(pos.y), " Z: ", FIXFLOAT(measured_z));

  restore_feedrate_and_scaling();

  #ifdef Z_AFTER_PROBING
    if (raise_after == PROBE_PT_STOW) probe.move_z_after_probing();
  #endif

  report_current_position();
}

#endif // HAS_BED_PROBE
