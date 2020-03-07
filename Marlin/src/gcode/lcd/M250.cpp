
#include "../../inc/MarlinConfig.h"

#if HAS_LCD_CONTRAST

#include "../gcode.h"
#include "../../lcd/ultralcd.h"

/**
 * M250: Read and optionally set the LCD contrast
 */
void GcodeSuite::M250() {
  if (parser.seen('C')) ui.set_contrast(parser.value_int());
  SERIAL_ECHOLNPAIR("LCD Contrast: ", ui.contrast);
}

#endif // HAS_LCD_CONTRAST
