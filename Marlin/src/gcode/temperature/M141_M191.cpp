
/**
 * gcode/temperature/M141_M191.cpp
 *
 * Chamber target temperature control
 */

#include "../../inc/MarlinConfig.h"

#if HAS_HEATED_CHAMBER

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
 * M141: Set chamber temperature
 */
void GcodeSuite::M141() {
  if (DEBUGGING(DRYRUN)) return;
  if (parser.seenval('S')) thermalManager.setTargetChamber(parser.value_celsius());
}

/**
 * M191: Sxxx Wait for chamber current temp to reach target temp. Waits only when heating
 *       Rxxx Wait for chamber current temp to reach target temp. Waits when heating and cooling
 */
void GcodeSuite::M191() {
  if (DEBUGGING(DRYRUN)) return;

  const bool no_wait_for_cooling = parser.seenval('S');
  if (no_wait_for_cooling || parser.seenval('R')) {
    thermalManager.setTargetChamber(parser.value_celsius());
    #if ENABLED(PRINTJOB_TIMER_AUTOSTART)
      thermalManager.check_timer_autostart(true, false);
    #endif
  }
  else return;

  const bool is_heating = thermalManager.isHeatingChamber();
  if (is_heating || !no_wait_for_cooling) {
    ui.set_status_P(is_heating ? GET_TEXT(MSG_CHAMBER_HEATING) : GET_TEXT(MSG_CHAMBER_COOLING));
    thermalManager.wait_for_chamber(false);
  }
}

#endif // HAS_HEATED_CHAMBER
