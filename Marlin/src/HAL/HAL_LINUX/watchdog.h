#pragma once

#define WDT_TIMEOUT   4000000 // 4 second timeout

void watchdog_init();
void HAL_watchdog_refresh();
