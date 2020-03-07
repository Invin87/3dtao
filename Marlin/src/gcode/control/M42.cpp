
#include "../gcode.h"
#include "../../MarlinCore.h" // for pin_is_protected
#include "../../inc/MarlinConfig.h"

#if FAN_COUNT > 0
  #include "../../module/temperature.h"
#endif

/**
 * M42: Change pin status via GCode
 *
 *  P<pin>  Pin number (LED if omitted)
 *          For LPC1768 specify pin P1_02 as M42 P102,
 *                                  P1_20 as M42 P120, etc.
 *
 *  S<byte> Pin status from 0 - 255
 *  I       Flag to ignore Marlin's pin protection
 */
void GcodeSuite::M42() {
  if (!parser.seenval('S')) return;
  const byte pin_status = parser.value_byte();

  const int pin_index = PARSED_PIN_INDEX('P', GET_PIN_MAP_INDEX(LED_PIN));
  if (pin_index < 0) return;

  const pin_t pin = GET_PIN_MAP_PIN(pin_index);

  #if FAN_COUNT > 0
    switch (pin) {
      #if HAS_FAN0
        case FAN0_PIN: thermalManager.fan_speed[0] = pin_status; return;
      #endif
      #if HAS_FAN1
        case FAN1_PIN: thermalManager.fan_speed[1] = pin_status; return;
      #endif
      #if HAS_FAN2
        case FAN2_PIN: thermalManager.fan_speed[2] = pin_status; return;
      #endif
      #if HAS_FAN3
        case FAN3_PIN: thermalManager.fan_speed[3] = pin_status; return;
      #endif
      #if HAS_FAN4
        case FAN4_PIN: thermalManager.fan_speed[4] = pin_status; return;
      #endif
      #if HAS_FAN5
        case FAN5_PIN: thermalManager.fan_speed[5] = pin_status; return;
      #endif
      #if HAS_FAN6
        case FAN6_PIN: thermalManager.fan_speed[6] = pin_status; return;
      #endif
      #if HAS_FAN7
        case FAN7_PIN: thermalManager.fan_speed[7] = pin_status; return;
      #endif
    }
  #endif

  if (!parser.boolval('I') && pin_is_protected(pin)) return protected_pin_err();

  pinMode(pin, OUTPUT);
  extDigitalWrite(pin, pin_status);
  analogWrite(pin, pin_status);
}
