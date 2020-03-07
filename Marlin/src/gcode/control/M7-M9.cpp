
#include "../../inc/MarlinConfig.h"

#if ENABLED(COOLANT_CONTROL)

#include "../gcode.h"
#include "../../module/planner.h"

#if ENABLED(COOLANT_MIST)
  /**
   * M7: Mist Coolant On
   */
  void GcodeSuite::M7() {
    planner.synchronize();                            // Wait for move to arrive
    WRITE(COOLANT_MIST_PIN, !(COOLANT_MIST_INVERT));  // Turn on Mist coolant
  }
#endif

#if ENABLED(COOLANT_FLOOD)
  /**
   * M8: Flood Coolant On
   */
  void GcodeSuite::M8() {
    planner.synchronize();                              // Wait for move to arrive
    WRITE(COOLANT_FLOOD_PIN, !(COOLANT_FLOOD_INVERT));  // Turn on Flood coolant
  }
#endif

/**
 * M9: Coolant OFF
 */
void GcodeSuite::M9() {
  planner.synchronize();                            // Wait for move to arrive
  #if ENABLED(COOLANT_MIST)
    WRITE(COOLANT_MIST_PIN, COOLANT_MIST_INVERT);   // Turn off Mist coolant
  #endif
  #if ENABLED(COOLANT_FLOOD)
    WRITE(COOLANT_FLOOD_PIN, COOLANT_FLOOD_INVERT); // Turn off Flood coolant
  #endif
}

#endif // COOLANT_CONTROL
