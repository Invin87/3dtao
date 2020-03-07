
#include "../../gcode.h"

#include "../../../inc/MarlinConfig.h"

#if HAS_CASE_LIGHT
  #include "../../../feature/caselight.h"

  /**
   * M355: Turn case light on/off and set brightness
   *
   *   P<byte>  Set case light brightness (PWM pin required - ignored otherwise)
   *
   *   S<bool>  Set case light on/off
   *
   *   When S turns on the light on a PWM pin then the current brightness level is used/restored
   *
   *   M355 P200 S0 turns off the light & sets the brightness level
   *   M355 S1 turns on the light with a brightness of 200 (assuming a PWM pin)
   */
  void GcodeSuite::M355() {
    uint8_t args = 0;
    if (parser.seenval('P')) {
      ++args, case_light_brightness = parser.value_byte();
      case_light_arg_flag = false;
    }
    if (parser.seenval('S')) {
      ++args, case_light_on = parser.value_bool();
      case_light_arg_flag = true;
    }
    if (args) update_case_light();

    // always report case light status
    SERIAL_ECHO_START();
    if (!case_light_on) {
      SERIAL_ECHOLNPGM("Case light: off");
    }
    else {
      if (!PWM_PIN(CASE_LIGHT_PIN)) SERIAL_ECHOLNPGM("Case light: on");
      else SERIAL_ECHOLNPAIR("Case light: ", case_light_brightness);
    }
  }
#endif // HAS_CASE_LIGHT
