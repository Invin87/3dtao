
#include "../../inc/MarlinConfig.h"

#if ENABLED(PIDTEMPBED)

#include "../gcode.h"
#include "../../module/temperature.h"

/**
 * M304 - Set and/or Report the current Bed PID values
 *
 *  P<pval> - Set the P value
 *  I<ival> - Set the I value
 *  D<dval> - Set the D value
 */
void GcodeSuite::M304() {
  if (parser.seen('P')) thermalManager.temp_bed.pid.Kp = parser.value_float();
  if (parser.seen('I')) thermalManager.temp_bed.pid.Ki = scalePID_i(parser.value_float());
  if (parser.seen('D')) thermalManager.temp_bed.pid.Kd = scalePID_d(parser.value_float());

  SERIAL_ECHO_START();
  SERIAL_ECHOLNPAIR(" p:", thermalManager.temp_bed.pid.Kp,
                    " i:", unscalePID_i(thermalManager.temp_bed.pid.Ki),
                    " d:", unscalePID_d(thermalManager.temp_bed.pid.Kd));
}

#endif // PIDTEMPBED
