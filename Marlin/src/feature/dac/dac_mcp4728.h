#pragma once

/**
 * Arduino library for MicroChip MCP4728 I2C D/A converter.
 */

#include "../../core/types.h"

#include <Wire.h>

/**
 * The following three macros are only used in this piece of code related to mcp4728.
 * They are defined in the standard Arduino framework but could be undefined in 32 bits Arduino frameworks.
 * (For instance not defined in Arduino lpc176x framework)
 * So we have to define them if needed.
 */
#ifndef word
  #define word(h, l)  ((uint8_t) ((h << 8) | l))
#endif

#ifndef lowByte
  #define lowByte(w)  ((uint8_t) ((w) & 0xff))
#endif

#ifndef highByte
  #define highByte(w) ((uint8_t) ((w) >> 8))
#endif

#define defaultVDD     DAC_STEPPER_MAX //was 5000 but differs with internal Vref
#define BASE_ADDR      0x60
#define RESET          0b00000110
#define WAKE           0b00001001
#define UPDATE         0b00001000
#define MULTIWRITE     0b01000000
#define SINGLEWRITE    0b01011000
#define SEQWRITE       0b01010000
#define VREFWRITE      0b10000000
#define GAINWRITE      0b11000000
#define POWERDOWNWRITE 0b10100000
#define GENERALCALL    0b00000000
#define GAINWRITE      0b11000000

// This is taken from the original lib, makes it easy to edit if needed
// DAC_OR_ADDRESS defined in pins_BOARD.h  file
#define DAC_DEV_ADDRESS (BASE_ADDR | DAC_OR_ADDRESS)

void mcp4728_init();
uint8_t mcp4728_analogWrite(const uint8_t channel, const uint16_t value);
uint8_t mcp4728_eepromWrite();
uint8_t mcp4728_setVref_all(const uint8_t value);
uint8_t mcp4728_setGain_all(const uint8_t value);
uint16_t mcp4728_getValue(const uint8_t channel);
uint8_t mcp4728_fastWrite();
uint8_t mcp4728_simpleCommand(const byte simpleCommand);
uint8_t mcp4728_getDrvPct(const uint8_t channel);
void mcp4728_setDrvPct(xyze_uint8_t &pct);
