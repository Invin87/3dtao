
// Custom User Menu

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(CUSTOM_USER_MENUS)

#include "menu.h"
#include "../../gcode/queue.h"

#ifdef USER_SCRIPT_DONE
  #define _DONE_SCRIPT "\n" USER_SCRIPT_DONE
#else
  #define _DONE_SCRIPT ""
#endif

void _lcd_user_gcode(PGM_P const cmd) {
  queue.inject_P(cmd);
  #if ENABLED(USER_SCRIPT_AUDIBLE_FEEDBACK) && HAS_BUZZER
    ui.completion_feedback();
  #endif
  #if ENABLED(USER_SCRIPT_RETURN)
    ui.return_to_status();
  #endif
}

void menu_user() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);
  #define HAS_USER_ITEM(N) (defined(USER_DESC_##N) && defined(USER_GCODE_##N))
  #define USER_ITEM(N) ACTION_ITEM_P(PSTR(USER_DESC_##N), []{ _lcd_user_gcode(PSTR(USER_GCODE_##N _DONE_SCRIPT)); });
  #if HAS_USER_ITEM(1)
    USER_ITEM(1);
  #endif
  #if HAS_USER_ITEM(2)
    USER_ITEM(2);
  #endif
  #if HAS_USER_ITEM(3)
    USER_ITEM(3);
  #endif
  #if HAS_USER_ITEM(4)
    USER_ITEM(4);
  #endif
  #if HAS_USER_ITEM(5)
    USER_ITEM(5);
  #endif
  #if HAS_USER_ITEM(6)
    USER_ITEM(6);
  #endif
  #if HAS_USER_ITEM(7)
    USER_ITEM(7);
  #endif
  #if HAS_USER_ITEM(8)
    USER_ITEM(8);
  #endif
  #if HAS_USER_ITEM(9)
    USER_ITEM(9);
  #endif
  #if HAS_USER_ITEM(10)
    USER_ITEM(10);
  #endif
  #if HAS_USER_ITEM(11)
    USER_ITEM(11);
  #endif
  #if HAS_USER_ITEM(12)
    USER_ITEM(12);
  #endif
  #if HAS_USER_ITEM(13)
    USER_ITEM(13);
  #endif
  #if HAS_USER_ITEM(14)
    USER_ITEM(14);
  #endif
  #if HAS_USER_ITEM(15)
    USER_ITEM(15);
  #endif
  #if HAS_USER_ITEM(16)
    USER_ITEM(16);
  #endif
  #if HAS_USER_ITEM(17)
    USER_ITEM(17);
  #endif
  #if HAS_USER_ITEM(18)
    USER_ITEM(18);
  #endif
  #if HAS_USER_ITEM(19)
    USER_ITEM(19);
  #endif
  #if HAS_USER_ITEM(20)
    USER_ITEM(20);
  #endif
  #if HAS_USER_ITEM(21)
    USER_ITEM(21);
  #endif
  #if HAS_USER_ITEM(22)
    USER_ITEM(22);
  #endif
  #if HAS_USER_ITEM(23)
    USER_ITEM(23);
  #endif
  #if HAS_USER_ITEM(24)
    USER_ITEM(24);
  #endif
  #if HAS_USER_ITEM(25)
    USER_ITEM(25);
  #endif
  END_MENU();
}

#endif // HAS_LCD_MENU && CUSTOM_USER_MENUS
