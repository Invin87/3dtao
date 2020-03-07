
/**
 * stepper/indirection.cpp
 *
 * Stepper motor driver indirection to allow some stepper functions to
 * be done via SPI/I2c instead of direct pin manipulation.
 *
 * Copyright (c) 2015 Dominik Wenger
 */

#include "../../inc/MarlinConfig.h"
#include "indirection.h"

void restore_stepper_drivers() {
  #if HAS_TRINAMIC
    restore_trinamic_drivers();
  #endif
}

void reset_stepper_drivers() {
  #if HAS_DRIVER(TMC26X)
    tmc26x_init_to_defaults();
  #endif

  #if HAS_L64XX
    L64xxManager.init_to_defaults();
  #endif

  #if HAS_TRINAMIC
    reset_trinamic_drivers();
  #endif
}
