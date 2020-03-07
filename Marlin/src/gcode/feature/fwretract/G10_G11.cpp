
#include "../../../inc/MarlinConfig.h"

#if ENABLED(FWRETRACT)

#include "../../../feature/fwretract.h"
#include "../../gcode.h"
#include "../../../module/motion.h"

/**
 * G10 - Retract filament according to settings of M207
 *       TODO: Handle 'G10 P' for tool settings and 'G10 L' for workspace settings
 */
void GcodeSuite::G10() {
  #if EXTRUDERS > 1
    const bool rs = parser.boolval('S');
  #endif
  fwretract.retract(true
    #if EXTRUDERS > 1
      , rs
    #endif
  );
}

/**
 * G11 - Recover filament according to settings of M208
 */
void GcodeSuite::G11() { fwretract.retract(false); }

#endif // FWRETRACT
