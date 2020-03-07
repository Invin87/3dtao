
/**
 * unified.cpp - Unified Bed Leveling
 */

#include "../../../inc/MarlinConfig.h"

#if ENABLED(AUTO_BED_LEVELING_UBL)

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
 *   M421 I<xindex> J<yindex> N
 *   M421 C Z<linear>
 *   M421 C Q<offset>
 */
void GcodeSuite::M421() {
  xy_int8_t ij = { int8_t(parser.intval('I', -1)), int8_t(parser.intval('J', -1)) };
  const bool hasI = ij.x >= 0,
             hasJ = ij.y >= 0,
             hasC = parser.seen('C'),
             hasN = parser.seen('N'),
             hasZ = parser.seen('Z'),
             hasQ = !hasZ && parser.seen('Q');

  if (hasC) ij = ubl.find_closest_mesh_point_of_type(REAL, current_position);

  if (int(hasC) + int(hasI && hasJ) != 1 || !(hasZ || hasQ || hasN))
    SERIAL_ERROR_MSG(STR_ERR_M421_PARAMETERS);
  else if (!WITHIN(ij.x, 0, GRID_MAX_POINTS_X - 1) || !WITHIN(ij.y, 0, GRID_MAX_POINTS_Y - 1))
    SERIAL_ERROR_MSG(STR_ERR_MESH_XY);
  else {
    float &zval = ubl.z_values[ij.x][ij.y];
    zval = hasN ? NAN : parser.value_linear_units() + (hasQ ? zval : 0);
    #if ENABLED(EXTENSIBLE_UI)
      ExtUI::onMeshUpdate(ij.x, ij.y, zval);
    #endif
  }
}

#endif // AUTO_BED_LEVELING_UBL
