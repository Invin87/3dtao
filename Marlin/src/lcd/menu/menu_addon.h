#pragma once

#include "../lcdprint.h"
#if HAS_GRAPHICAL_LCD
  #include "../dogm/ultralcd_DOGM.h"
#endif

#define MENU_ITEM_ADDON_START(X) do{ \
  if (ui.should_draw() && _menuLineNr == _thisItemNr - 1) { \
    SETCURSOR(X, _lcdLineNr)

#define MENU_ITEM_ADDON_END() } }while(0)
