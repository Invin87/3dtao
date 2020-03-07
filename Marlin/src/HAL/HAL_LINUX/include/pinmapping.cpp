
#ifdef __PLAT_LINUX__

#include <pinmapping.h>

#include "../../../gcode/parser.h"

uint8_t analog_offset = NUM_DIGITAL_PINS - NUM_ANALOG_INPUTS;

// Get the digital pin for an analog index
pin_t analogInputToDigitalPin(const int8_t p) {
  return (WITHIN(p, 0, NUM_ANALOG_INPUTS) ? analog_offset + p : P_NC);
}

// Return the index of a pin number
int16_t GET_PIN_MAP_INDEX(const pin_t pin) {
  return pin;
}

// Test whether the pin is valid
bool VALID_PIN(const pin_t p) {
  return WITHIN(p, 0, NUM_DIGITAL_PINS);
}

// Get the analog index for a digital pin
int8_t DIGITAL_PIN_TO_ANALOG_PIN(const pin_t p) {
  return (WITHIN(p, analog_offset, NUM_DIGITAL_PINS) ? p - analog_offset : P_NC);
}

// Test whether the pin is PWM
bool PWM_PIN(const pin_t p) {
  return false;
}

// Test whether the pin is interruptable
bool INTERRUPT_PIN(const pin_t p) {
  return false;
}

// Get the pin number at the given index
pin_t GET_PIN_MAP_PIN(const int16_t ind) {
  return ind;
}

int16_t PARSED_PIN_INDEX(const char code, const int16_t dval) {
  return parser.intval(code, dval);
}

#endif // __PLAT_LINUX__
