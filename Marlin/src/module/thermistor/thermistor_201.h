#pragma once

#define REVERSE_TEMP_SENSOR_RANGE

// Pt100 with LMV324 amp on Overlord v1.1 electronics
const short temptable_201[][2] PROGMEM = {
  { OV(   0),   0 },
  { OV(   8),   1 },
  { OV(  23),   6 },
  { OV(  41),  15 },
  { OV(  51),  20 },
  { OV(  68),  28 },
  { OV(  74),  30 },
  { OV(  88),  35 },
  { OV(  99),  40 },
  { OV( 123),  50 },
  { OV( 148),  60 },
  { OV( 173),  70 },
  { OV( 198),  80 },
  { OV( 221),  90 },
  { OV( 245), 100 },
  { OV( 269), 110 },
  { OV( 294), 120 },
  { OV( 316), 130 },
  { OV( 342), 140 },
  { OV( 364), 150 },
  { OV( 387), 160 },
  { OV( 412), 170 },
  { OV( 433), 180 },
  { OV( 456), 190 },
  { OV( 480), 200 },
  { OV( 500), 210 },
  { OV( 548), 224 },
  { OV( 572), 233 },
  { OV(1155), 490 }
};
