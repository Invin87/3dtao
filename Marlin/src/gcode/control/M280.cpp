
#include "../../inc/MarlinConfig.h"

#if HAS_SERVOS

#include "../gcode.h"
#include "../../module/servo.h"

/**
 * M280: Get or set servo position. P<index> [S<angle>]
 */
void GcodeSuite::M280() {
  if (!parser.seen('P')) return;
  const int servo_index = parser.value_int();
  if (WITHIN(servo_index, 0, NUM_SERVOS - 1)) {
    if (parser.seen('S')) {
      const int a = parser.value_int();
      if (a == -1)
        servo[servo_index].detach();
      else
        MOVE_SERVO(servo_index, a);
    }
    else {
      SERIAL_ECHO_START();
      SERIAL_ECHOLNPAIR(" Servo ", servo_index, ": ", servo[servo_index].read());
    }
  }
  else {
    SERIAL_ERROR_START();
    SERIAL_ECHOLNPAIR("Servo ", servo_index, " out of range");
  }
}

#endif // HAS_SERVOS
