#include "../../inc/MarlinConfig.h"

#if ENABLED(EDITABLE_SERVO_ANGLES)

#include "../gcode.h"
#include "../../module/servo.h"

void GcodeSuite::M281() {
  if (!parser.seenval('P')) return;
  const int servo_index = parser.value_int();
  if (WITHIN(servo_index, 0, NUM_SERVOS - 1)) {
    #if ENABLED(BLTOUCH)
      if (servo_index == Z_PROBE_SERVO_NR) {
        SERIAL_ERROR_MSG("BLTouch angles can't be changed.");
        return;
      }
    #endif
    bool angle_change = false;
    if (parser.seen('L')) {
      servo_angles[servo_index][0] = parser.value_int();
      angle_change = true;
    }
    if (parser.seen('U')) {
      servo_angles[servo_index][1] = parser.value_int();
      angle_change = true;
    }
    if (!angle_change) {
      SERIAL_ECHO_START();
      SERIAL_ECHOLNPAIR(" Servo ", servo_index,
                        " L", servo_angles[servo_index][0],
                        " U", servo_angles[servo_index][1]);
    }
  }
  else {
    SERIAL_ERROR_START();
    SERIAL_ECHOLNPAIR("Servo ", servo_index, " out of range");
  }
}

#endif // EDITABLE_SERVO_ANGLES
