
/**
 * lcdprint.cpp
 */

#include "../inc/MarlinConfigPre.h"

#if HAS_SPI_LCD

#include "lcdprint.h"
#include "../core/language.h"

/**
 * lcd_put_u8str_ind_P
 * Print a string with an index substituted within it
 */
lcd_uint_t lcd_put_u8str_ind_P(PGM_P const pstr, const uint8_t ind, const lcd_uint_t maxlen/*=LCD_WIDTH*/) {
  uint8_t *p = (uint8_t*)pstr;
  lcd_uint_t n = maxlen;
  for (; n; n--) {
    wchar_t ch;
    p = get_utf8_value_cb(p, read_byte_rom, &ch);
    if (!ch) break;
    if (ch == '=' || ch == '~' || ch == '*') {
      if (ch == '*') { lcd_put_wchar('E'); n--; }
      // lcd_put_int(ind); n--; if (ind >= 10) n--;
      // if (ind >= 0)
        {
          lcd_put_wchar(ind + ((ch == '=') ? '0' : LCD_FIRST_TOOL));
          n--;
        }
      // else if (ind == -1) { PGM_P const b = GET_TEXT(MSG_BED); lcd_put_u8str_P(b); n -= utf8_strlen_P(b); }
      // else if (ind == -2) { PGM_P const c = GET_TEXT(MSG_CHAMBER); lcd_put_u8str_P(c); n -= utf8_strlen_P(c); }
      if (n) n -= lcd_put_u8str_max_P((PGM_P)p, n);
      break;
    }
    lcd_put_wchar(ch);
  }
  return n;
}

#endif // HAS_SPI_LCD
