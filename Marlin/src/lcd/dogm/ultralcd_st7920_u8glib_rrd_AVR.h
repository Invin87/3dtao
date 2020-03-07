#pragma once

// NOTE - the HAL version of the rrd device uses a generic ST7920 device.  See the
// file u8g_dev_st7920_128x64_HAL.cpp for the HAL version.

#include "../../inc/MarlinConfig.h"
#include "../../HAL/shared/Delay.h"

#define ST7920_CLK_PIN  LCD_PINS_D4
#define ST7920_DAT_PIN  LCD_PINS_ENABLE
#define ST7920_CS_PIN   LCD_PINS_RS

//#define PAGE_HEIGHT 8   // 128 byte framebuffer
#define PAGE_HEIGHT 16    // 256 byte framebuffer
//#define PAGE_HEIGHT 32  // 512 byte framebuffer

#include <U8glib.h>

// If you want you can define your own set of delays in Configuration.h
//#define ST7920_DELAY_1 DELAY_NS(0)
//#define ST7920_DELAY_2 DELAY_NS(0)
//#define ST7920_DELAY_3 DELAY_NS(0)

#if F_CPU >= 20000000
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(0)
  #define CPU_ST7920_DELAY_3 DELAY_NS(50)
#elif MB(3DRAG, K8200, K8400, SILVER_GATE)
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(188)
  #define CPU_ST7920_DELAY_3 DELAY_NS(0)
#elif MB(MINIRAMBO, EINSY_RAMBO, EINSY_RETRO)
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(250)
  #define CPU_ST7920_DELAY_3 DELAY_NS(0)
#elif MB(RAMBO)
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(0)
  #define CPU_ST7920_DELAY_3 DELAY_NS(0)
#elif MB(BQ_ZUM_MEGA_3D)
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(0)
  #define CPU_ST7920_DELAY_3 DELAY_NS(189)
#elif defined(ARDUINO_ARCH_STM32)
  #define CPU_ST7920_DELAY_1 DELAY_NS(300)
  #define CPU_ST7920_DELAY_2 DELAY_NS(40)
  #define CPU_ST7920_DELAY_3 DELAY_NS(340)
#elif F_CPU == 16000000
  #define CPU_ST7920_DELAY_1 DELAY_NS(0)
  #define CPU_ST7920_DELAY_2 DELAY_NS(0)
  #define CPU_ST7920_DELAY_3 DELAY_NS(63)
#else
  #error "No valid condition for delays in 'ultralcd_st7920_u8glib_rrd_AVR.h'"
#endif

void ST7920_SWSPI_SND_8BIT(uint8_t val);

#if DOGM_SPI_DELAY_US > 0
  #define U8G_DELAY() DELAY_US(DOGM_SPI_DELAY_US)
#else
  #define U8G_DELAY() DELAY_US(10)
#endif

#define ST7920_CS()              { WRITE(ST7920_CS_PIN,1); U8G_DELAY(); }
#define ST7920_NCS()             { WRITE(ST7920_CS_PIN,0); }
#define ST7920_SET_CMD()         { ST7920_SWSPI_SND_8BIT(0xF8); U8G_DELAY(); }
#define ST7920_SET_DAT()         { ST7920_SWSPI_SND_8BIT(0xFA); U8G_DELAY(); }
#define ST7920_WRITE_BYTE(a)     { ST7920_SWSPI_SND_8BIT((uint8_t)((a)&0xF0u)); ST7920_SWSPI_SND_8BIT((uint8_t)((a)<<4u)); U8G_DELAY(); }
#define ST7920_WRITE_BYTES(p,l)  { for (uint8_t i = l + 1; --i;) { ST7920_SWSPI_SND_8BIT(*p&0xF0); ST7920_SWSPI_SND_8BIT(*p<<4); p++; } U8G_DELAY(); }
