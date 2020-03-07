
/**
 * extui_dgus_lcd.cpp
 *
 * DGUS implementation for Marlin by coldtobi, Feb-May 2019
 */

#include "../inc/MarlinConfigPre.h"

#if HAS_DGUS_LCD

#include "extensible_ui/ui_api.h"
#include "extensible_ui/lib/dgus/DGUSDisplay.h"
#include "extensible_ui/lib/dgus/DGUSDisplayDefinition.h"

extern const char NUL_STR[];

namespace ExtUI {

  void onStartup() {
    dgusdisplay.InitDisplay();
    ScreenHandler.UpdateScreenVPData();
  }

  void onIdle() { ScreenHandler.loop(); }

  void onPrinterKilled(PGM_P error, PGM_P component) {
    ScreenHandler.sendinfoscreen(GET_TEXT(MSG_HALTED), error, NUL_STR, GET_TEXT(MSG_PLEASE_RESET), true, true, true, true);
    ScreenHandler.GotoScreen(DGUSLCD_SCREEN_KILL);
    while (!ScreenHandler.loop());  // Wait while anything is left to be sent
  }

  void onMediaInserted() {
    #if ENABLED(SDSUPPORT)
      ScreenHandler.SDCardInserted();
    #endif
  }
  void onMediaError()    {
    #if ENABLED(SDSUPPORT)
      ScreenHandler.SDCardError();
    #endif
  }
  void onMediaRemoved()  {
    #if ENABLED(SDSUPPORT)
      ScreenHandler.SDCardRemoved();
    #endif
  }

  void onPlayTone(const uint16_t frequency, const uint16_t duration) {}
  void onPrintTimerStarted() {}
  void onPrintTimerPaused() {}
  void onPrintTimerStopped() {}
  void onFilamentRunout(const extruder_t extruder) {}

  void onUserConfirmRequired(const char * const msg) {
    if (msg) {
      ScreenHandler.sendinfoscreen(PSTR("Please confirm."), nullptr, msg, nullptr, true, true, false, true);
      ScreenHandler.SetupConfirmAction(ExtUI::setUserConfirmed);
      ScreenHandler.GotoScreen(DGUSLCD_SCREEN_POPUP);
    }
    else if (ScreenHandler.getCurrentScreen() == DGUSLCD_SCREEN_POPUP ) {
      ScreenHandler.SetupConfirmAction(nullptr);
      ScreenHandler.PopToOldScreen();
    }
  }

  void onStatusChanged(const char * const msg) { ScreenHandler.setstatusmessage(msg); }

  void onFactoryReset() {}
  void onStoreSettings(char *buff) {
    // Called when saving to EEPROM (i.e. M500). If the ExtUI needs
    // permanent data to be stored, it can write up to eeprom_data_size bytes
    // into buff.

    // Example:
    //  static_assert(sizeof(myDataStruct) <= ExtUI::eeprom_data_size);
    //  memcpy(buff, &myDataStruct, sizeof(myDataStruct));
  }

  void onLoadSettings(const char *buff) {
    // Called while loading settings from EEPROM. If the ExtUI
    // needs to retrieve data, it should copy up to eeprom_data_size bytes
    // from buff

    // Example:
    //  static_assert(sizeof(myDataStruct) <= ExtUI::eeprom_data_size);
    //  memcpy(&myDataStruct, buff, sizeof(myDataStruct));
  }

  void onConfigurationStoreWritten(bool success) {
    // Called after the entire EEPROM has been written,
    // whether successful or not.
  }

  void onConfigurationStoreRead(bool success) {
    // Called after the entire EEPROM has been read,
    // whether successful or not.
  }

  void onMeshUpdate(const int8_t xpos, const int8_t ypos, const float zval) {
    // Called when any mesh points are updated
  }

  #if ENABLED(POWER_LOSS_RECOVERY)
    void OnPowerLossResume() {
      // Called on resume from power-loss
      ScreenHandler.GotoScreen(DGUSLCD_SCREEN_POWER_LOSS);
    }
  #endif


  #if HAS_PID_HEATING
    void OnPidTuning(const result_t rst) {
      // Called for temperature PID tuning result
      SERIAL_ECHOLNPAIR("OnPidTuning:",rst);
      switch(rst) {
        case PID_BAD_EXTRUDER_NUM:
          ScreenHandler.setstatusmessagePGM(PSTR(STR_PID_BAD_EXTRUDER_NUM));
          break;
        case PID_TEMP_TOO_HIGH:
          ScreenHandler.setstatusmessagePGM(PSTR(STR_PID_TEMP_TOO_HIGH));
          break;
        case PID_TUNING_TIMEOUT:
          ScreenHandler.setstatusmessagePGM(PSTR(STR_PID_TIMEOUT));
          break;
        case PID_DONE:
          ScreenHandler.setstatusmessagePGM(PSTR(STR_PID_AUTOTUNE_FINISHED));
          break;
      }
      ScreenHandler.GotoScreen(DGUSLCD_SCREEN_MAIN);
    }
  #endif

}
#endif // HAS_DGUS_LCD
