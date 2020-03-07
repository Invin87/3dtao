
/**
 * M421.cpp - Auto Bed Leveling
 */

#include "../../../inc/MarlinConfig.h"

#if ENABLED(AUTO_BED_LEVELING_BILINEAR)

#include "../../gcode.h"
#include "../../../feature/bedlevel/bedlevel.h"

#if ENABLED(EXTENSIBLE_UI)
  #include "../../../lcd/extensible_ui/ui_api.h"
#endif

/**
 * M421: Set a single Mesh Bed Leveling Z coordinate
 *
 * Usage:
 *   M421 I<xindex> J<yindex> Z<linear>
 *   M421 I<xindex> J<yindex> Q<offset>
 */
void GcodeSuite::M421() {
  int8_t ix = parser.intval('I', -1), iy = parser.intval('J', -1);
  const bool hasI = ix >= 0,
             hasJ = iy >= 0,
             hasZ = parser.seen('Z'),
             hasQ = !hasZ && parser.seen('Q');

  if (!hasI || !hasJ || !(hasZ || hasQ))
    SERIAL_ERROR_MSG(STR_ERR_M421_PARAMETERS);
  else if (!WITHIN(ix, 0, GRID_MAX_POINTS_X - 1) || !WITHIN(iy, 0, GRID_MAX_POINTS_Y - 1))
    SERIAL_ERROR_MSG(STR_ERR_MESH_XY);
  else {
    z_values[ix][iy] = parser.value_linear_units() + (hasQ ? z_values[ix][iy] : 0);
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      bed_level_virt_interpolate();
    #endif
    #if ENABLED(EXTENSIBLE_UI)
      ExtUI::onMeshUpdate(ix, iy, z_values[ix][iy]);
    #endif
  }
}

#endif // AUTO_BED_LEVELING_BILINEAR
