
// Backlash Menu

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(BACKLASH_GCODE)

#include "menu.h"

#include "../../feature/backlash.h"

void menu_backlash() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);

  EDIT_ITEM_FAST(percent, MSG_BACKLASH_CORRECTION, &backlash.correction, all_off, all_on);

  #define EDIT_BACKLASH_DISTANCE(N) EDIT_ITEM_FAST(float43, MSG_BACKLASH_##N, &backlash.distance_mm[_AXIS(N)], 0.0f, 9.9f);
  EDIT_BACKLASH_DISTANCE(A);
  EDIT_BACKLASH_DISTANCE(B);
  EDIT_BACKLASH_DISTANCE(C);

  #ifdef BACKLASH_SMOOTHING_MM
    EDIT_ITEM_FAST(float43, MSG_BACKLASH_SMOOTHING, &backlash.smoothing_mm, 0.0f, 9.9f);
  #endif

  END_MENU();
}

#endif // HAS_LCD_MENU && BACKLASH_COMPENSATION
