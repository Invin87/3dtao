
#include "FlushableHardwareSerial.h"

#ifdef ARDUINO_ARCH_ESP32

FlushableHardwareSerial::FlushableHardwareSerial(int uart_nr)
    : HardwareSerial(uart_nr)
{}

FlushableHardwareSerial flushableSerial(0);

#endif // ARDUINO_ARCH_ESP32
