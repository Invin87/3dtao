
// Spindle / Laser Menu

#include "../../inc/MarlinConfig.h"

#if HAS_LCD_MENU && HAS_CUTTER

  #include "menu.h"

  #include "../../feature/spindle_laser.h"

  void menu_spindle_laser() {

    START_MENU();
    BACK_ITEM(MSG_MAIN);
    if (cutter.enabled()) {
      #if ENABLED(SPINDLE_LASER_PWM)
        EDIT_ITEM(CUTTER_MENU_TYPE, MSG_CUTTER(POWER), &cutter.power, SPEED_POWER_MIN, SPEED_POWER_MAX);
      #endif
      ACTION_ITEM(MSG_CUTTER(OFF), cutter.disable);
    }
    else {
      ACTION_ITEM(MSG_CUTTER(ON), cutter.enable_forward);
      #if ENABLED(SPINDLE_CHANGE_DIR)
        ACTION_ITEM(MSG_SPINDLE_REVERSE, cutter.enable_reverse);
      #endif
    }
    END_MENU();
  }

#endif // HAS_LCD_MENU && HAS_CUTTER
