
#ifdef TARGET_LPC1768

#include "../../inc/MarlinConfigPre.h"
#include "MarlinSerial.h"

#if (defined(SERIAL_PORT) && SERIAL_PORT == 0) || (defined(SERIAL_PORT_2) && SERIAL_PORT_2 == 0) || (defined(DGUS_SERIAL_PORT) && DGUS_SERIAL_PORT == 0)
  MarlinSerial MSerial(LPC_UART0);
  extern "C" void UART0_IRQHandler() {
    MSerial.IRQHandler();
  }
#endif

#if SERIAL_PORT == 1 || SERIAL_PORT_2 == 1 || DGUS_SERIAL_PORT == 1
  MarlinSerial MSerial1((LPC_UART_TypeDef *) LPC_UART1);
  extern "C" void UART1_IRQHandler() {
    MSerial1.IRQHandler();
  }
#endif

#if SERIAL_PORT == 2 || SERIAL_PORT_2 == 2 || DGUS_SERIAL_PORT == 2
  MarlinSerial MSerial2(LPC_UART2);
  extern "C" void UART2_IRQHandler() {
    MSerial2.IRQHandler();
  }
#endif

#if SERIAL_PORT == 3 || SERIAL_PORT_2 == 3 || DGUS_SERIAL_PORT == 3
  MarlinSerial MSerial3(LPC_UART3);
  extern "C" void UART3_IRQHandler() {
    MSerial3.IRQHandler();
  }
#endif

#endif // TARGET_LPC1768
