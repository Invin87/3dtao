#pragma once

// R25 = 100 kOhm, beta25 = 4267 K, 1 kOhm pull-up,
// 100k ATC Semitec 104GT-2 (Used on ParCan) (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
// Verified by linagee. Source: http://shop.arcol.hu/static/datasheets/thermistors.pdf
// Calculated using 1kohm pullup, voltage divider math, and manufacturer provided temp/resistance
// Advantage: More resolution and better linearity from 150C to 200C
const short temptable_55[][2] PROGMEM = {
  { OV(   1), 500 },
  { OV(  76), 300 },
  { OV(  87), 290 },
  { OV( 100), 280 },
  { OV( 114), 270 },
  { OV( 131), 260 },
  { OV( 152), 250 },
  { OV( 175), 240 },
  { OV( 202), 230 },
  { OV( 234), 220 },
  { OV( 271), 210 },
  { OV( 312), 200 },
  { OV( 359), 190 },
  { OV( 411), 180 },
  { OV( 467), 170 },
  { OV( 527), 160 },
  { OV( 590), 150 },
  { OV( 652), 140 },
  { OV( 713), 130 },
  { OV( 770), 120 },
  { OV( 822), 110 },
  { OV( 867), 100 },
  { OV( 905),  90 },
  { OV( 936),  80 },
  { OV( 961),  70 },
  { OV( 979),  60 },
  { OV( 993),  50 },
  { OV(1003),  40 },
  { OV(1010),  30 },
  { OV(1015),  20 },
  { OV(1018),  10 },
  { OV(1020),   0 }
};
