#pragma once

/**
 * MarlinSerialUSB_Due.h - Hardware Serial over USB (CDC) library for Arduino DUE
 * Copyright (c) 2017 Eduardo José Tagle. All right reserved
 */

#include "../../inc/MarlinConfig.h"

#if SERIAL_PORT == -1

#include <WString.h>

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class MarlinSerialUSB {

public:
  MarlinSerialUSB() {};
  static void begin(const long);
  static void end();
  static int peek();
  static int read();
  static void flush();
  static void flushTX();
  static bool available();
  static void write(const uint8_t c);

  #if ENABLED(SERIAL_STATS_DROPPED_RX)
    FORCE_INLINE static uint32_t dropped() { return 0; }
  #endif

  #if ENABLED(SERIAL_STATS_MAX_RX_QUEUED)
    FORCE_INLINE static int rxMaxEnqueued() { return 0; }
  #endif

  FORCE_INLINE static void write(const char* str) { while (*str) write(*str++); }
  FORCE_INLINE static void write(const uint8_t* buffer, size_t size) { while (size--) write(*buffer++); }
  FORCE_INLINE static void print(const String& s) { for (int i = 0; i < (int)s.length(); i++) write(s[i]); }
  FORCE_INLINE static void print(const char* str) { write(str); }

  static void print(char, int = 0);
  static void print(unsigned char, int = 0);
  static void print(int, int = DEC);
  static void print(unsigned int, int = DEC);
  static void print(long, int = DEC);
  static void print(unsigned long, int = DEC);
  static void print(double, int = 2);

  static void println(const String& s);
  static void println(const char[]);
  static void println(char, int = 0);
  static void println(unsigned char, int = 0);
  static void println(int, int = DEC);
  static void println(unsigned int, int = DEC);
  static void println(long, int = DEC);
  static void println(unsigned long, int = DEC);
  static void println(double, int = 2);
  static void println();
  operator bool() { return true; }

private:
  static void printNumber(unsigned long, const uint8_t);
  static void printFloat(double, uint8_t);
};

extern MarlinSerialUSB customizedSerial1;

#endif // SERIAL_PORT == -1