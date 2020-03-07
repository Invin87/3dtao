
#include "../../inc/MarlinConfig.h"

#if IS_KINEMATIC

#include "../gcode.h"
#include "../../module/motion.h"

#if ENABLED(DELTA)

  #include "../../module/delta.h"
  /**
   * M665: Set delta configurations
   *
   *    H = delta height
   *    L = diagonal rod
   *    R = delta radius
   *    S = segments per second
   *    X = Alpha (Tower 1) angle trim
   *    Y = Beta (Tower 2) angle trim
   *    Z = Gamma (Tower 3) angle trim
   */
  void GcodeSuite::M665() {
    if (parser.seen('H')) delta_height              = parser.value_linear_units();
    if (parser.seen('L')) delta_diagonal_rod        = parser.value_linear_units();
    if (parser.seen('R')) delta_radius              = parser.value_linear_units();
    if (parser.seen('S')) delta_segments_per_second = parser.value_float();
    if (parser.seen('X')) delta_tower_angle_trim.a  = parser.value_float();
    if (parser.seen('Y')) delta_tower_angle_trim.b  = parser.value_float();
    if (parser.seen('Z')) delta_tower_angle_trim.c  = parser.value_float();
    recalc_delta_settings();
  }

#elif IS_SCARA

  #include "../../module/scara.h"

  /**
   * M665: Set SCARA settings
   *
   * Parameters:
   *
   *   S[segments-per-second] - Segments-per-second
   *   P[theta-psi-offset]    - Theta-Psi offset, added to the shoulder (A/X) angle
   *   T[theta-offset]        - Theta     offset, added to the elbow    (B/Y) angle
   *   Z[z-offset]            - Z offset, added to Z
   *
   *   A, P, and X are all aliases for the shoulder angle
   *   B, T, and Y are all aliases for the elbow angle
   */
  void GcodeSuite::M665() {
    if (parser.seenval('S')) delta_segments_per_second = parser.value_float();

    #if HAS_SCARA_OFFSET

      if (parser.seenval('Z')) scara_home_offset.z = parser.value_linear_units();

      const bool hasA = parser.seenval('A'), hasP = parser.seenval('P'), hasX = parser.seenval('X');
      const uint8_t sumAPX = hasA + hasP + hasX;
      if (sumAPX) {
        if (sumAPX == 1)
          scara_home_offset.a = parser.value_float();
        else {
          SERIAL_ERROR_MSG("Only one of A, P, or X is allowed.");
          return;
        }
      }

      const bool hasB = parser.seenval('B'), hasT = parser.seenval('T'), hasY = parser.seenval('Y');
      const uint8_t sumBTY = hasB + hasT + hasY;
      if (sumBTY) {
        if (sumBTY == 1)
          scara_home_offset.b = parser.value_float();
        else {
          SERIAL_ERROR_MSG("Only one of B, T, or Y is allowed.");
          return;
        }
      }

    #endif // HAS_SCARA_OFFSET
  }

#endif

#endif // IS_KINEMATIC
