#pragma once

// Pt100 with 1k0 pullup
const short temptable_110[][2] PROGMEM = {
  // only a few values are needed as the curve is very flat
  PtLine(  0, 100, 1000),
  PtLine( 50, 100, 1000),
  PtLine(100, 100, 1000),
  PtLine(150, 100, 1000),
  PtLine(200, 100, 1000),
  PtLine(250, 100, 1000),
  PtLine(300, 100, 1000)
};
