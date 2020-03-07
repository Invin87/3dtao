
/**
 * G29.cpp - Unified Bed Leveling
 */

#include "../../../inc/MarlinConfig.h"

#if ENABLED(AUTO_BED_LEVELING_UBL)

#include "../../gcode.h"
#include "../../../feature/bedlevel/bedlevel.h"

void GcodeSuite::G29() { ubl.G29(); }

#endif // AUTO_BED_LEVELING_UBL
