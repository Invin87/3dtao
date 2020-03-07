
#include "../../inc/MarlinConfig.h"

#if HAS_BED_PROBE

#include "../gcode.h"
#include "../../feature/bedlevel/bedlevel.h"
#include "../../module/probe.h"

extern const char SP_Y_STR[], SP_Z_STR[];

/**
 * M851: Set the nozzle-to-probe offsets in current units
 */
void GcodeSuite::M851() {

  // Show usage with no parameters
  if (!parser.seen("XYZ")) {
    SERIAL_ECHOLNPAIR_P(
      #if HAS_PROBE_XY_OFFSET
        PSTR(STR_PROBE_OFFSET " X"), probe.offset_xy.x, SP_Y_STR, probe.offset_xy.y, SP_Z_STR
      #else
        PSTR(STR_PROBE_OFFSET " X0 Y0 Z")
      #endif
      , probe.offset.z
    );
    return;
  }

  // Start with current offsets and modify
  xyz_pos_t offs = probe.offset;

  // Assume no errors
  bool ok = true;

  if (parser.seenval('X')) {
    const float x = parser.value_float();
    #if HAS_PROBE_XY_OFFSET
      if (WITHIN(x, -(X_BED_SIZE), X_BED_SIZE))
        offs.x = x;
      else {
        SERIAL_ECHOLNPAIR("?X out of range (-", int(X_BED_SIZE), " to ", int(X_BED_SIZE), ")");
        ok = false;
      }
    #else
      if (x) SERIAL_ECHOLNPAIR("?X must be 0 (NOZZLE_AS_PROBE)."); // ...but let 'ok' stay true
    #endif
  }

  if (parser.seenval('Y')) {
    const float y = parser.value_float();
    #if HAS_PROBE_XY_OFFSET
      if (WITHIN(y, -(Y_BED_SIZE), Y_BED_SIZE))
        offs.y = y;
      else {
        SERIAL_ECHOLNPAIR("?Y out of range (-", int(Y_BED_SIZE), " to ", int(Y_BED_SIZE), ")");
        ok = false;
      }
    #else
      if (y) SERIAL_ECHOLNPAIR("?Y must be 0 (NOZZLE_AS_PROBE)."); // ...but let 'ok' stay true
    #endif
  }

  if (parser.seenval('Z')) {
    const float z = parser.value_float();
    if (WITHIN(z, Z_PROBE_OFFSET_RANGE_MIN, Z_PROBE_OFFSET_RANGE_MAX))
      offs.z = z;
    else {
      SERIAL_ECHOLNPAIR("?Z out of range (", int(Z_PROBE_OFFSET_RANGE_MIN), " to ", int(Z_PROBE_OFFSET_RANGE_MAX), ")");
      ok = false;
    }
  }

  // Save the new offsets
  if (ok) probe.offset = offs;
}

#endif // HAS_BED_PROBE
