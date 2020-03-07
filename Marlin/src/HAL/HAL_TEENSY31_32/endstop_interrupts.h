#pragma once

/**
 * Endstop Interrupts
 *
 * Without endstop interrupts the endstop pins must be polled continually in
 * the temperature-ISR via endstops.update(), most of the time finding no change.
 * With this feature endstops.update() is called only when we know that at
 * least one endstop has changed state, saving valuable CPU cycles.
 *
 * This feature only works when all used endstop pins can generate an 'external interrupt'.
 *
 * Test whether pins issue interrupts on your board by flashing 'pin_interrupt_test.ino'.
 * (Located in Marlin/buildroot/share/pin_interrupt_test/pin_interrupt_test.ino)
 */

#include "../../module/endstops.h"

// One ISR for all EXT-Interrupts
void endstop_ISR() { endstops.update(); }

/**
 *  Endstop interrupts for Due based targets.
 *  On Due, all pins support external interrupt capability.
 */

void setup_endstop_interrupts() {
  #define _ATTACH(P) attachInterrupt(digitalPinToInterrupt(P), endstop_ISR, CHANGE)
  #if HAS_X_MAX
    _ATTACH(X_MAX_PIN);
  #endif
  #if HAS_X_MIN
    _ATTACH(X_MIN_PIN);
  #endif
  #if HAS_Y_MAX
    _ATTACH(Y_MAX_PIN);
  #endif
  #if HAS_Y_MIN
    _ATTACH(Y_MIN_PIN);
  #endif
  #if HAS_Z_MAX
    _ATTACH(Z_MAX_PIN);
  #endif
  #if HAS_Z_MIN
     _ATTACH(Z_MIN_PIN);
  #endif
  #if HAS_Z2_MAX
    _ATTACH(Z2_MAX_PIN);
  #endif
  #if HAS_Z2_MIN
    _ATTACH(Z2_MIN_PIN);
  #endif
  #if HAS_Z_MIN_PROBE_PIN
    _ATTACH(Z_MIN_PROBE_PIN);
  #endif
}
