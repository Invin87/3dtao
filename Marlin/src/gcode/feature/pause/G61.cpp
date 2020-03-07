
#include "../../../inc/MarlinConfig.h"

#if SAVED_POSITIONS

#include "../../../core/language.h"
#include "../../../module/planner.h"
#include "../../gcode.h"
#include "../../../module/motion.h"

/**
 * G61: Return to saved position
 *
 *   F<rate>  - Feedrate (optional) for the move back.
 *   S<slot>  - Slot # (0-based) to restore from (default 0).
 *   X Y Z    - Axes to restore. At least one is required.
 */
void GcodeSuite::G61(void) {

  const uint8_t slot = parser.byteval('S');

  #if SAVED_POSITIONS < 256
    if (slot >= SAVED_POSITIONS) {
      SERIAL_ERROR_MSG(STR_INVALID_POS_SLOT STRINGIFY(SAVED_POSITIONS));
      return;
    }
  #endif

  // No saved position? No axes being restored?
  if (!TEST(saved_slots[slot >> 3], slot & 0x07) || !parser.seen("XYZ")) return;

  // Apply any given feedrate over 0.0
  const float fr = parser.linearval('F');
  if (fr > 0.0) feedrate_mm_s = MMM_TO_MMS(fr);

  SERIAL_ECHOPAIR(STR_RESTORING_POS " S", int(slot));
  LOOP_XYZ(i) {
    destination[i] = parser.seen(axis_codes[i])
      ? stored_position[slot][i] + parser.value_axis_units((AxisEnum)i)
      : current_position[i];
    SERIAL_CHAR(' ', axis_codes[i]);
    SERIAL_ECHO_F(destination[i]);
  }
  SERIAL_EOL();

  // Move to the saved position
  prepare_move_to_destination();
}

#endif // SAVED_POSITIONS
