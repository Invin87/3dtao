#pragma once

// Pt1000 with 4k7 pullup
const short temptable_1047[][2] PROGMEM = {
  // only a few values are needed as the curve is very flat
  PtLine(  0, 1000, 4700),
  PtLine( 50, 1000, 4700),
  PtLine(100, 1000, 4700),
  PtLine(150, 1000, 4700),
  PtLine(200, 1000, 4700),
  PtLine(250, 1000, 4700),
  PtLine(300, 1000, 4700)
};
