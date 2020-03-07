#pragma once

/**
 * HAL/HAL_ST7920.h
 * For the HALs that provide direct access to the ST7920 display
 * (bypassing U8G), it will allow the LIGHTWEIGHT_UI to operate.
 */

#if HAS_GRAPHICAL_LCD && ENABLED(LIGHTWEIGHT_UI)
  void ST7920_cs();
  void ST7920_ncs();
  void ST7920_set_cmd();
  void ST7920_set_dat();
  void ST7920_write_byte(const uint8_t data);
#endif
