#pragma once

#ifdef ARDUINO_ARCH_ESP32

#include <HardwareSerial.h>

class FlushableHardwareSerial : public HardwareSerial {
public:
  FlushableHardwareSerial(int uart_nr);

  inline void flushTX() { /* No need to flush the hardware serial, but defined here for compatibility. */ }
};

extern FlushableHardwareSerial flushableSerial;

#endif // ARDUINO_ARCH_ESP32
