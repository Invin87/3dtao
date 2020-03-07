
#include "../../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "../gcode.h"
#include "../../module/motion.h"
#include "../../module/probe.h"

/**
 * M401: Deploy and activate the Z probe
 */
void GcodeSuite::M401() {
  probe.deploy();
  report_current_position();
}

/**
 * M402: Deactivate and stow the Z probe
 */
void GcodeSuite::M402() {
  probe.stow();
  #ifdef Z_AFTER_PROBING
    probe.move_z_after_probing();
  #endif
  report_current_position();
}

#endif // HAS_BED_PROBE
