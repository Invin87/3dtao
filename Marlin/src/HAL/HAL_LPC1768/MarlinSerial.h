#pragma once

#include <HardwareSerial.h>
#include <WString.h>

#include "../../inc/MarlinConfigPre.h"
#if ENABLED(EMERGENCY_PARSER)
  #include "../../feature/emergency_parser.h"
#endif

#ifndef SERIAL_PORT
  #define SERIAL_PORT 0
#endif
#ifndef RX_BUFFER_SIZE
  #define RX_BUFFER_SIZE 128
#endif
#ifndef TX_BUFFER_SIZE
  #define TX_BUFFER_SIZE 32
#endif

class MarlinSerial : public HardwareSerial<RX_BUFFER_SIZE, TX_BUFFER_SIZE> {
public:
  MarlinSerial(LPC_UART_TypeDef *UARTx) :
    HardwareSerial<RX_BUFFER_SIZE, TX_BUFFER_SIZE>(UARTx)
    #if ENABLED(EMERGENCY_PARSER)
       , emergency_state(EmergencyParser::State::EP_RESET)
    #endif
    {
    }

  void end() {}

  #if ENABLED(EMERGENCY_PARSER)
    bool recv_callback(const char c) override {
      emergency_parser.update(emergency_state, c);
      return true; // do not discard character
    }

    EmergencyParser::State emergency_state;
  #endif
};

extern MarlinSerial MSerial;
extern MarlinSerial MSerial1;
extern MarlinSerial MSerial2;
extern MarlinSerial MSerial3;
