
#include "../../inc/MarlinConfig.h"

#if ENABLED(PREVENT_COLD_EXTRUSION)

#include "../gcode.h"
#include "../../module/temperature.h"

/**
 * M302: Allow cold extrudes, or set the minimum extrude temperature
 *
 *       S<temperature> sets the minimum extrude temperature
 *       P<bool> enables (1) or disables (0) cold extrusion
 *
 *  Examples:
 *
 *       M302         ; report current cold extrusion state
 *       M302 P0      ; enable cold extrusion checking
 *       M302 P1      ; disables cold extrusion checking
 *       M302 S0      ; always allow extrusion (disables checking)
 *       M302 S170    ; only allow extrusion above 170
 *       M302 S170 P1 ; set min extrude temp to 170 but leave disabled
 */
void GcodeSuite::M302() {
  const bool seen_S = parser.seen('S');
  if (seen_S) {
    thermalManager.extrude_min_temp = parser.value_celsius();
    thermalManager.allow_cold_extrude = (thermalManager.extrude_min_temp == 0);
  }

  if (parser.seen('P'))
    thermalManager.allow_cold_extrude = (thermalManager.extrude_min_temp == 0) || parser.value_bool();
  else if (!seen_S) {
    // Report current state
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM("Cold extrudes are ");
    serialprintPGM(thermalManager.allow_cold_extrude ? PSTR("en") : PSTR("dis"));
    SERIAL_ECHOLNPAIR("abled (min temp ", thermalManager.extrude_min_temp, "C)");
  }
}

#endif // PREVENT_COLD_EXTRUSION
