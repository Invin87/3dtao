#pragma once

/**
 * stepper_dac.h   - To set stepper current via DAC
 */

#include "dac_mcp4728.h"

int dac_init();
void dac_current_percent(uint8_t channel, float val);
void dac_current_raw(uint8_t channel, uint16_t val);
void dac_print_values();
void dac_commit_eeprom();
uint8_t dac_current_get_percent(AxisEnum axis);
void dac_current_set_percents(xyze_uint8_t &pct);
