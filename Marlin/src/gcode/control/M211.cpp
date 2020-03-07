
#include "../../inc/MarlinConfigPre.h"

#if HAS_SOFTWARE_ENDSTOPS

#include "../gcode.h"
#include "../../module/motion.h"

/**
 * M211: Enable, Disable, and/or Report software endstops
 *
 * Usage: M211 S1 to enable, M211 S0 to disable, M211 alone for report
 */
void GcodeSuite::M211() {
  const xyz_pos_t l_soft_min = soft_endstop.min.asLogical(),
                  l_soft_max = soft_endstop.max.asLogical();
  SERIAL_ECHO_START();
  SERIAL_ECHOPGM(STR_SOFT_ENDSTOPS);
  if (parser.seen('S')) soft_endstops_enabled = parser.value_bool();
  serialprint_onoff(soft_endstops_enabled);
  print_xyz(l_soft_min, PSTR(STR_SOFT_MIN), PSTR(" "));
  print_xyz(l_soft_max, PSTR(STR_SOFT_MAX));
}

#endif
