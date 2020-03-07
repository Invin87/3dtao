#pragma once

extern IWDG_HandleTypeDef hiwdg;

void watchdog_init();
void HAL_watchdog_refresh();
