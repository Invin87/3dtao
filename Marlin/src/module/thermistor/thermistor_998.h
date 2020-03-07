#pragma once

// User-defined table 1
// Dummy Thermistor table.. It will ALWAYS read a fixed value.
#ifndef DUMMY_THERMISTOR_998_VALUE
  #define DUMMY_THERMISTOR_998_VALUE 25
#endif

const short temptable_998[][2] PROGMEM = {
  { OV(   1), DUMMY_THERMISTOR_998_VALUE },
  { OV(1023), DUMMY_THERMISTOR_998_VALUE }
};
