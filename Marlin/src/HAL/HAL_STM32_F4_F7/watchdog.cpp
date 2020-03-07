
#if defined(STM32GENERIC) && (defined(STM32F4) || defined(STM32F7))

#include "../../inc/MarlinConfig.h"

#if ENABLED(USE_WATCHDOG)

  #include "watchdog.h"

  IWDG_HandleTypeDef hiwdg;

  void watchdog_init() {
    hiwdg.Instance = IWDG;
    hiwdg.Init.Prescaler = IWDG_PRESCALER_32; //32kHz LSI clock and 32x prescalar = 1024Hz IWDG clock
    hiwdg.Init.Reload = 4095;           //4095 counts = 4 seconds at 1024Hz
    if (HAL_IWDG_Init(&hiwdg) != HAL_OK) {
      //Error_Handler();
    }
    else {
      #if PIN_EXISTS(LED) && DISABLED(PINS_DEBUGGING)
        TOGGLE(LED_PIN);  // heartbeat indicator
      #endif
    }
  }

  void HAL_watchdog_refresh() {
    /* Refresh IWDG: reload counter */
    if (HAL_IWDG_Refresh(&hiwdg) != HAL_OK) {
      /* Refresh Error */
      //Error_Handler();
    }
  }

#endif // USE_WATCHDOG
#endif // STM32GENERIC && (STM32F4 || STM32F7)
