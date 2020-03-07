
#include "../../../inc/MarlinConfig.h"

#if ENABLED(POWER_LOSS_RECOVERY)

#include "../../gcode.h"
#include "../../../feature/power_loss_recovery.h"
#include "../../../module/motion.h"
#include "../../../lcd/ultralcd.h"
#if ENABLED(EXTENSIBLE_UI)
  #include "../../../lcd/extensible_ui/ui_api.h"
#endif

#define DEBUG_OUT ENABLED(DEBUG_POWER_LOSS_RECOVERY)
#include "../../../core/debug_out.h"

void menu_job_recovery();

inline void plr_error(PGM_P const prefix) {
  #if ENABLED(DEBUG_POWER_LOSS_RECOVERY)
    DEBUG_ECHO_START();
    serialprintPGM(prefix);
    DEBUG_ECHOLNPGM(" Power-Loss Recovery Data");
  #else
    UNUSED(prefix);
  #endif
}

#if HAS_LCD_MENU
  void lcd_power_loss_recovery_cancel();
#endif

/**
 * M1000: Resume from power-loss (undocumented)
 *   - With 'S' go to the Resume/Cancel menu
 *   - With no parameters, run recovery commands
 */
void GcodeSuite::M1000() {

  if (recovery.valid()) {
    if (parser.seen('S')) {
      #if HAS_LCD_MENU
        ui.goto_screen(menu_job_recovery);
      #elif ENABLED(EXTENSIBLE_UI)
        ExtUI::OnPowerLossResume();
      #else
        SERIAL_ECHO_MSG("Resume requires LCD.");
      #endif
    }
    else if (parser.seen('C')) {
      #if HAS_LCD_MENU
        lcd_power_loss_recovery_cancel();
      #else
        recovery.cancel();
      #endif
      #if ENABLED(EXTENSIBLE_UI)
        ExtUI::onPrintTimerStopped();
      #endif
    }
    else
      recovery.resume();
  }
  else
    plr_error(recovery.info.valid_head ? PSTR("No") : PSTR("Invalid"));

}

#endif // POWER_LOSS_RECOVERY