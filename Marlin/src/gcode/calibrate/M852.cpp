
#include "../../inc/MarlinConfig.h"

#if ENABLED(SKEW_CORRECTION_GCODE)

#include "../gcode.h"
#include "../../module/planner.h"

/**
 * M852: Get or set the machine skew factors. Reports current values with no arguments.
 *
 *  S[xy_factor] - Alias for 'I'
 *  I[xy_factor] - New XY skew factor
 *  J[xz_factor] - New XZ skew factor
 *  K[yz_factor] - New YZ skew factor
 */
void GcodeSuite::M852() {
  uint8_t ijk = 0, badval = 0, setval = 0;

  if (parser.seen('I') || parser.seen('S')) {
    ++ijk;
    const float value = parser.value_linear_units();
    if (WITHIN(value, SKEW_FACTOR_MIN, SKEW_FACTOR_MAX)) {
      if (planner.skew_factor.xy != value) {
        planner.skew_factor.xy = value;
        ++setval;
      }
    }
    else
      ++badval;
  }

  #if ENABLED(SKEW_CORRECTION_FOR_Z)

    if (parser.seen('J')) {
      ++ijk;
      const float value = parser.value_linear_units();
      if (WITHIN(value, SKEW_FACTOR_MIN, SKEW_FACTOR_MAX)) {
        if (planner.skew_factor.xz != value) {
          planner.skew_factor.xz = value;
          ++setval;
        }
      }
      else
        ++badval;
    }

    if (parser.seen('K')) {
      ++ijk;
      const float value = parser.value_linear_units();
      if (WITHIN(value, SKEW_FACTOR_MIN, SKEW_FACTOR_MAX)) {
        if (planner.skew_factor.yz != value) {
          planner.skew_factor.yz = value;
          ++setval;
        }
      }
      else
        ++badval;
    }

  #endif

  if (badval)
    SERIAL_ECHOLNPGM(STR_SKEW_MIN " " STRINGIFY(SKEW_FACTOR_MIN) " " STR_SKEW_MAX " " STRINGIFY(SKEW_FACTOR_MAX));

  // When skew is changed the current position changes
  if (setval) {
    set_current_from_steppers_for_axis(ALL_AXES);
    sync_plan_position();
    report_current_position();
  }

  if (!ijk) {
    SERIAL_ECHO_START();
    serialprintPGM(GET_TEXT(MSG_SKEW_FACTOR));
    SERIAL_ECHOPAIR_F(" XY: ", planner.skew_factor.xy, 6);
    #if ENABLED(SKEW_CORRECTION_FOR_Z)
      SERIAL_ECHOPAIR_F(" XZ: ", planner.skew_factor.xz, 6);
      SERIAL_ECHOPAIR_F(" YZ: ", planner.skew_factor.yz, 6);
    #endif
    SERIAL_EOL();
  }
}

#endif // SKEW_CORRECTION_GCODE
