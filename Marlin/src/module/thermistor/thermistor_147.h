#pragma once

// Pt100 with 4k7 pullup
const short temptable_147[][2] PROGMEM = {
  // only a few values are needed as the curve is very flat
  PtLine(  0, 100, 4700),
  PtLine( 50, 100, 4700),
  PtLine(100, 100, 4700),
  PtLine(150, 100, 4700),
  PtLine(200, 100, 4700),
  PtLine(250, 100, 4700),
  PtLine(300, 100, 4700)
};
