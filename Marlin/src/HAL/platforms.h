#pragma once

#ifdef __AVR__
  #define HAL_PLATFORM HAL_AVR
#elif defined(ARDUINO_ARCH_SAM)
  #define HAL_PLATFORM HAL_DUE
#elif defined(__MK20DX256__)
  #define HAL_PLATFORM HAL_TEENSY31_32
#elif defined(__MK64FX512__) || defined(__MK66FX1M0__)
  #define HAL_PLATFORM HAL_TEENSY35_36
#elif defined(TARGET_LPC1768)
  #define HAL_PLATFORM HAL_LPC1768
#elif defined(__STM32F1__) || defined(TARGET_STM32F1)
  #define HAL_PLATFORM HAL_STM32F1
#elif defined(STM32GENERIC) && (defined(STM32F4) || defined(STM32F7))
  #define HAL_PLATFORM HAL_STM32_F4_F7
#elif defined(ARDUINO_ARCH_STM32)
  #define HAL_PLATFORM HAL_STM32
#elif defined(ARDUINO_ARCH_ESP32)
  #define HAL_PLATFORM HAL_ESP32
#elif defined(__PLAT_LINUX__)
  #define HAL_PLATFORM HAL_LINUX
#elif defined(__SAMD51__)
  #define HAL_PLATFORM HAL_SAMD51
#else
  #error "Unsupported Platform!"
#endif

#define XSTR_(M) #M
#define XSTR(M) XSTR_(M)
#define HAL_PATH(PATH, NAME) XSTR(PATH/HAL_PLATFORM/NAME)
