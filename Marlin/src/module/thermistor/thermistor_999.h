#pragma once

// User-defined table 2
// Dummy Thermistor table.. It will ALWAYS read a fixed value.
#ifndef DUMMY_THERMISTOR_999_VALUE
  #define DUMMY_THERMISTOR_999_VALUE 25
#endif

const short temptable_999[][2] PROGMEM = {
  { OV(   1), DUMMY_THERMISTOR_999_VALUE },
  { OV(1023), DUMMY_THERMISTOR_999_VALUE }
};
