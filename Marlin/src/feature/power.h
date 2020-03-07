#pragma once

/**
 * power.h - power control
 */

#include "../core/millis_t.h"

class Power {
  public:
    static void check();
    static void power_on();
    static void power_off();
  private:
    static millis_t lastPowerOn;
    static bool is_power_needed();
};

extern Power powerManager;
