
#include "../gcode.h"
#include "../../MarlinCore.h" // for stepper_inactive_time, disable_e_steppers
#include "../../lcd/ultralcd.h"
#include "../../module/stepper.h"

#if BOTH(AUTO_BED_LEVELING_UBL, ULTRA_LCD)
  #include "../../feature/bedlevel/bedlevel.h"
#endif

/**
 * M17: Enable stepper motors
 */
void GcodeSuite::M17() {
  if (parser.seen("XYZE")) {
    if (parser.seen('X')) ENABLE_AXIS_X();
    if (parser.seen('Y')) ENABLE_AXIS_Y();
    if (parser.seen('Z')) ENABLE_AXIS_Z();
    #if HAS_E_STEPPER_ENABLE
      if (parser.seen('E')) enable_e_steppers();
    #endif
  }
  else {
    LCD_MESSAGEPGM(MSG_NO_MOVE);
    enable_all_steppers();
  }
}

/**
 * M18, M84: Disable stepper motors
 */
void GcodeSuite::M18_M84() {
  if (parser.seenval('S')) {
    stepper_inactive_time = parser.value_millis_from_seconds();
  }
  else {
    if (parser.seen("XYZE")) {
      planner.synchronize();
      if (parser.seen('X')) DISABLE_AXIS_X();
      if (parser.seen('Y')) DISABLE_AXIS_Y();
      if (parser.seen('Z')) DISABLE_AXIS_Z();
      #if HAS_E_STEPPER_ENABLE
        if (parser.seen('E')) disable_e_steppers();
      #endif
    }
    else
      planner.finish_and_disable();

    #if HAS_LCD_MENU && ENABLED(AUTO_BED_LEVELING_UBL)
      if (ubl.lcd_map_control) {
        ubl.lcd_map_control = false;
        ui.defer_status_screen(false);
      }
    #endif
  }
}
