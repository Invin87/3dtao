
#include "../gcode.h"
#include "../../module/printcounter.h"
#include "../../lcd/ultralcd.h"

#include "../../MarlinCore.h" // for startOrResumeJob

/**
 * M75: Start print timer
 */
void GcodeSuite::M75() {
  startOrResumeJob();
}

/**
 * M76: Pause print timer
 */
void GcodeSuite::M76() {
  print_job_timer.pause();
}

/**
 * M77: Stop print timer
 */
void GcodeSuite::M77() {
  print_job_timer.stop();
}

#if ENABLED(PRINTCOUNTER)

/**
 * M78: Show print statistics
 */
void GcodeSuite::M78() {
  if (parser.intval('S') == 78) {  // "M78 S78" will reset the statistics
    print_job_timer.initStats();
    ui.reset_status();
    return;
  }

  #if HAS_SERVICE_INTERVALS
    if (parser.seenval('R')) {
      print_job_timer.resetServiceInterval(parser.value_int());
      ui.reset_status();
      return;
    }
  #endif

  print_job_timer.showStats();
}

#endif // PRINTCOUNTER
