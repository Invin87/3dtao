
#include "../../../inc/MarlinConfig.h"

#if ENABLED(POWER_LOSS_RECOVERY)

#include "../../gcode.h"
#include "../../../feature/power_loss_recovery.h"
#include "../../../module/motion.h"
#include "../../../lcd/ultralcd.h"

/**
 * M413: Enable / Disable power-loss recovery
 *
 * Parameters
 *   S[bool] - Flag to enable / disable.
 *             If omitted, report current state.
 */
void GcodeSuite::M413() {

  if (parser.seen('S'))
    recovery.enable(parser.value_bool());
  else {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM("Power-loss recovery ");
    serialprintln_onoff(recovery.enabled);
  }

  #if ENABLED(DEBUG_POWER_LOSS_RECOVERY)
    if (parser.seen("RL")) recovery.load();
    if (parser.seen('W')) recovery.save(true);
    if (parser.seen('P')) recovery.purge();
    if (parser.seen('E')) serialprintPGM(recovery.exists() ? PSTR("PLR Exists\n") : PSTR("No PLR\n"));
    if (parser.seen('V')) serialprintPGM(recovery.valid() ? PSTR("Valid\n") : PSTR("Invalid\n"));
  #endif
}

#endif // POWER_LOSS_RECOVERY
