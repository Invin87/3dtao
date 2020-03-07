
/**
 * gcode/temperature/M140_M190.cpp
 *
 * Bed target temperature control
 */

#include "../../inc/MarlinConfig.h"

#if HAS_HEATED_BED

#include "../gcode.h"
#include "../../module/temperature.h"
#include "../../module/motion.h"
#include "../../lcd/ultralcd.h"

#if ENABLED(PRINTJOB_TIMER_AUTOSTART)
  #include "../../module/printcounter.h"
#endif

#if ENABLED(PRINTER_EVENT_LEDS)
  #include "../../feature/leds/leds.h"
#endif

#include "../../MarlinCore.h" // for wait_for_heatup, idle, startOrResumeJob

/**
 * M140: Set bed temperature
 */
void GcodeSuite::M140() {
  if (DEBUGGING(DRYRUN)) return;
  if (parser.seenval('S')) thermalManager.setTargetBed(parser.value_celsius());

  #if ENABLED(PRINTJOB_TIMER_AUTOSTART)
    /**
     * Stop the timer at the end of print. Both hotend and bed target
     * temperatures need to be set below mintemp. Order of M140 and M104
     * at the end of the print does not matter.
     */
    thermalManager.check_timer_autostart(false, true);
  #endif
}

/**
 * M190: Sxxx Wait for bed current temp to reach target temp. Waits only when heating
 *       Rxxx Wait for bed current temp to reach target temp. Waits when heating and cooling
 *
 * With PRINTJOB_TIMER_AUTOSTART also start the job timer on heating.
 */
void GcodeSuite::M190() {
  if (DEBUGGING(DRYRUN)) return;

  const bool no_wait_for_cooling = parser.seenval('S');
  if (no_wait_for_cooling || parser.seenval('R')) {
    thermalManager.setTargetBed(parser.value_celsius());
    #if ENABLED(PRINTJOB_TIMER_AUTOSTART)
      thermalManager.check_timer_autostart(true, false);
    #endif
  }
  else return;

  ui.set_status_P(thermalManager.isHeatingBed() ? GET_TEXT(MSG_BED_HEATING) : GET_TEXT(MSG_BED_COOLING));

  thermalManager.wait_for_bed(no_wait_for_cooling);
}

#endif // HAS_HEATED_BED
