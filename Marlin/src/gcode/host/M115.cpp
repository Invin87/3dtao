
#include "../gcode.h"
#include "../../inc/MarlinConfig.h"

#if ENABLED(EXTENDED_CAPABILITIES_REPORT)
  static void cap_line(PGM_P const name, bool ena=false) {
    SERIAL_ECHOPGM("Cap:");
    serialprintPGM(name);
    SERIAL_CHAR(':');
    SERIAL_ECHOLN(int(ena ? 1 : 0));
  }
#endif

/**
 * M115: Capabilities string and extended capabilities report
 *       If a capability is not reported, hosts should assume
 *       the capability is not present.
 */
void GcodeSuite::M115() {

  SERIAL_ECHOLNPGM(STR_M115_REPORT);

  #if ENABLED(EXTENDED_CAPABILITIES_REPORT)

    // PAREN_COMMENTS
    #if ENABLED(PAREN_COMMENTS)
      cap_line(PSTR("PAREN_COMMENTS"), true);
    #endif

    // QUOTED_STRINGS
    #if ENABLED(GCODE_QUOTED_STRINGS)
      cap_line(PSTR("QUOTED_STRINGS"), true);
    #endif

    // SERIAL_XON_XOFF
    cap_line(PSTR("SERIAL_XON_XOFF")
      #if ENABLED(SERIAL_XON_XOFF)
        , true
      #endif
    );

    // BINARY_FILE_TRANSFER (M28 B1)
    cap_line(PSTR("BINARY_FILE_TRANSFER")
      #if ENABLED(BINARY_FILE_TRANSFER)
        , true
      #endif
    );

    // EEPROM (M500, M501)
    cap_line(PSTR("EEPROM")
      #if ENABLED(EEPROM_SETTINGS)
        , true
      #endif
    );

    // Volumetric Extrusion (M200)
    cap_line(PSTR("VOLUMETRIC")
      #if DISABLED(NO_VOLUMETRICS)
        , true
      #endif
    );

    // AUTOREPORT_TEMP (M155)
    cap_line(PSTR("AUTOREPORT_TEMP")
      #if ENABLED(AUTO_REPORT_TEMPERATURES)
        , true
      #endif
    );

    // PROGRESS (M530 S L, M531 <file>, M532 X L)
    cap_line(PSTR("PROGRESS"));

    // Print Job timer M75, M76, M77
    cap_line(PSTR("PRINT_JOB"), true);

    // AUTOLEVEL (G29)
    cap_line(PSTR("AUTOLEVEL")
      #if HAS_AUTOLEVEL
        , true
      #endif
    );

    // Z_PROBE (G30)
    cap_line(PSTR("Z_PROBE")
      #if HAS_BED_PROBE
        , true
      #endif
    );

    // MESH_REPORT (M420 V)
    cap_line(PSTR("LEVELING_DATA")
      #if HAS_LEVELING
        , true
      #endif
    );

    // BUILD_PERCENT (M73)
    cap_line(PSTR("BUILD_PERCENT")
      #if ENABLED(LCD_SET_PROGRESS_MANUALLY)
        , true
      #endif
    );

    // SOFTWARE_POWER (M80, M81)
    cap_line(PSTR("SOFTWARE_POWER")
      #if ENABLED(PSU_CONTROL)
        , true
      #endif
    );

    // CASE LIGHTS (M355)
    cap_line(PSTR("TOGGLE_LIGHTS")
      #if HAS_CASE_LIGHT
        , true
      #endif
    );
    cap_line(PSTR("CASE_LIGHT_BRIGHTNESS")
      #if HAS_CASE_LIGHT
        , PWM_PIN(CASE_LIGHT_PIN)
      #endif
    );

    // EMERGENCY_PARSER (M108, M112, M410, M876)
    cap_line(PSTR("EMERGENCY_PARSER")
      #if ENABLED(EMERGENCY_PARSER)
        , true
      #endif
    );

    // PROMPT SUPPORT (M876)
    cap_line(PSTR("PROMPT_SUPPORT")
      #if ENABLED(HOST_PROMPT_SUPPORT)
        , true
      #endif
    );

    // AUTOREPORT_SD_STATUS (M27 extension)
    cap_line(PSTR("AUTOREPORT_SD_STATUS")
      #if ENABLED(AUTO_REPORT_SD_STATUS)
        , true
      #endif
    );

    // THERMAL_PROTECTION
    cap_line(PSTR("THERMAL_PROTECTION")
      #if (ENABLED(THERMAL_PROTECTION_HOTENDS) || !EXTRUDERS) && (ENABLED(THERMAL_PROTECTION_BED) || !HAS_HEATED_BED) && (ENABLED(THERMAL_PROTECTION_CHAMBER) || !HAS_HEATED_CHAMBER)
        , true
      #endif
    );

    // MOTION_MODES (M80-M89)
    cap_line(PSTR("MOTION_MODES")
      #if ENABLED(GCODE_MOTION_MODES)
        , true
      #endif
    );

    // CHAMBER_TEMPERATURE (M141, M191)
    cap_line(PSTR("CHAMBER_TEMPERATURE")
      #if HAS_HEATED_CHAMBER
        , true
      #endif
    );

  #endif // EXTENDED_CAPABILITIES_REPORT
}