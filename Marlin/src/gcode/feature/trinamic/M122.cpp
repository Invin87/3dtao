
#include "../../../inc/MarlinConfig.h"

#if HAS_TRINAMIC

#include "../../gcode.h"
#include "../../../feature/tmc_util.h"

/**
 * M122: Debug TMC drivers
 */
void GcodeSuite::M122() {
  xyze_bool_t print_axis = { false, false, false, false };
  bool print_all = true;
  LOOP_XYZE(i) if (parser.seen(axis_codes[i])) { print_axis[i] = true; print_all = false; }

  if (print_all) LOOP_XYZE(i) print_axis[i] = true;

  #if ENABLED(TMC_DEBUG)
    #if ENABLED(MONITOR_DRIVER_STATUS)
      const bool sflag = parser.seen('S'), s0 = sflag && !parser.value_bool();
      if (sflag) tmc_set_report_interval(s0 ? 0 : MONITOR_DRIVER_STATUS_INTERVAL_MS);
      if (!s0 && parser.seenval('P')) tmc_set_report_interval(_MIN(parser.value_ushort(), MONITOR_DRIVER_STATUS_INTERVAL_MS));
    #endif

    if (parser.seen('V'))
      tmc_get_registers(print_axis.x, print_axis.y, print_axis.z, print_axis.e);
    else
      tmc_report_all(print_axis.x, print_axis.y, print_axis.z, print_axis.e);
  #endif

  test_tmc_connection(print_axis.x, print_axis.y, print_axis.z, print_axis.e);
}

#endif // HAS_TRINAMIC
