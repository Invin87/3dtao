
#include "../../inc/MarlinConfig.h"

#if ENABLED(LCD_SET_PROGRESS_MANUALLY)

#include "../gcode.h"
#include "../../lcd/ultralcd.h"
#include "../../sd/cardreader.h"

/**
 * M73: Set percentage complete (for display on LCD)
 *
 * Example:
 *   M73 P25 ; Set progress to 25%
 *
 * Notes:
 *   This has no effect during an SD print job
 */
void GcodeSuite::M73() {
  if (parser.seen('P'))
    ui.set_progress((PROGRESS_SCALE) > 1
      ? parser.value_float() * (PROGRESS_SCALE)
      : parser.value_byte()
    );
  #if BOTH(LCD_SET_PROGRESS_MANUALLY, USE_M73_REMAINING_TIME)
    if (parser.seen('R')) ui.set_remaining_time(60 * parser.value_ulong());
  #endif
}

#endif // LCD_SET_PROGRESS_MANUALLY
