
#include "../../../inc/MarlinConfig.h"

#if HAS_COLOR_LEDS

#include "../../gcode.h"
#include "../../../feature/leds/leds.h"

/**
 * M150: Set Status LED Color - Use R-U-B-W for R-G-B-W
 *       and Brightness       - Use P (for NEOPIXEL only)
 *
 * Always sets all 3 or 4 components. If a component is left out, set to 0.
 *                                    If brightness is left out, no value changed
 *
 * Examples:
 *
 *   M150 R255       ; Turn LED red
 *   M150 R255 U127  ; Turn LED orange (PWM only)
 *   M150            ; Turn LED off
 *   M150 R U B      ; Turn LED white
 *   M150 W          ; Turn LED white using a white LED
 *   M150 P127       ; Set LED 50% brightness
 *   M150 P          ; Set LED full brightness
 */
void GcodeSuite::M150() {
  leds.set_color(MakeLEDColor(
    parser.seen('R') ? (parser.has_value() ? parser.value_byte() : 255) : 0,
    parser.seen('U') ? (parser.has_value() ? parser.value_byte() : 255) : 0,
    parser.seen('B') ? (parser.has_value() ? parser.value_byte() : 255) : 0,
    parser.seen('W') ? (parser.has_value() ? parser.value_byte() : 255) : 0,
    parser.seen('P') ? (parser.has_value() ? parser.value_byte() : 255) : neo.brightness()
  ));
}

#endif // HAS_COLOR_LEDS
