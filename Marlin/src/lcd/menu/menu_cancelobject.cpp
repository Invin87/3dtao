
// Cancel Object Menu

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(CANCEL_OBJECTS)

#include "menu.h"
#include "menu_addon.h"

#include "../../feature/cancel_object.h"

static void lcd_cancel_object_confirm() {
  const int8_t v = MenuItemBase::itemIndex;
  const char item_num[] = {
    ' ',
    char((v > 9) ? '0' + (v / 10) : ' '),
    char('0' + (v % 10)),
    '\0'
  };
  MenuItem_confirm::confirm_screen(
    []{
      cancelable.cancel_object(MenuItemBase::itemIndex - 1);
      #if HAS_BUZZER
        ui.completion_feedback();
      #endif
      ui.goto_previous_screen();
    },
    ui.goto_previous_screen,
    GET_TEXT(MSG_CANCEL_OBJECT), item_num, PSTR("?")
  );
}

void menu_cancelobject() {
  START_MENU();
  BACK_ITEM(MSG_MAIN);

  // Draw cancelable items in a loop
  int8_t a = cancelable.active_object;
  for (int8_t i = -1; i < cancelable.object_count; i++) {
    if (i == a) continue;
    int8_t j = i < 0 ? a : i;
    if (!cancelable.is_canceled(j))
      SUBMENU_N(j, MSG_CANCEL_OBJECT_N, lcd_cancel_object_confirm);
    if (i < 0) SKIP_ITEM();
  }

  END_MENU();
}

#endif // HAS_LCD_MENU && CANCEL_OBJECTS
