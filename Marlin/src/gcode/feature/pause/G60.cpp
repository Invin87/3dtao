
#include "../../../inc/MarlinConfig.h"

#if SAVED_POSITIONS

#include "../../../core/language.h"
#include "../../gcode.h"
#include "../../../module/motion.h"

#define DEBUG_OUT ENABLED(SAVED_POSITIONS_DEBUG)
#include "../../../core/debug_out.h"

/**
 * G60: Save current position
 *
 *   S<slot> - Memory slot # (0-based) to save into (default 0)
 */
void GcodeSuite::G60() {
  const uint8_t slot = parser.byteval('S');

  if (slot >= SAVED_POSITIONS) {
    SERIAL_ERROR_MSG(STR_INVALID_POS_SLOT STRINGIFY(SAVED_POSITIONS));
    return;
  }

  stored_position[slot] = current_position;
  SBI(saved_slots[slot >> 3], slot & 0x07);

  #if ENABLED(SAVED_POSITIONS_DEBUG)
    const xyze_pos_t &pos = stored_position[slot];
    DEBUG_ECHOPAIR_F(STR_SAVED_POS " S", slot);
    DEBUG_ECHOPAIR_F(" : X", pos.x);
    DEBUG_ECHOPAIR_F_P(SP_Y_STR, pos.y);
    DEBUG_ECHOLNPAIR_F_P(SP_Z_STR, pos.z);
  #endif
}

#endif // SAVED_POSITIONS
