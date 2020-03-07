#pragma once

#include "../../inc/MarlinConfigPre.h"

#if ENABLED(PROBE_MANUALLY)
  extern bool g29_in_progress;
#else
  constexpr bool g29_in_progress = false;
#endif

bool leveling_is_valid();
void set_bed_leveling_enabled(const bool enable=true);
void reset_bed_level();

#if ENABLED(ENABLE_LEVELING_FADE_HEIGHT)
  void set_z_fade_height(const float zfh, const bool do_report=true);
#endif

#if EITHER(MESH_BED_LEVELING, PROBE_MANUALLY)
  void _manual_goto_xy(const xy_pos_t &pos);
#endif

/**
 * A class to save and change the bed leveling state,
 * then restore it when it goes out of scope.
 */
class TemporaryBedLevelingState {
  bool saved;
  public:
    TemporaryBedLevelingState(const bool enable);
    ~TemporaryBedLevelingState() { set_bed_leveling_enabled(saved); }
};
#define TEMPORARY_BED_LEVELING_STATE(enable) const TemporaryBedLevelingState tbls(enable)

#if HAS_MESH

  typedef float bed_mesh_t[GRID_MAX_POINTS_X][GRID_MAX_POINTS_Y];

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)
    #include "abl/abl.h"
  #elif ENABLED(AUTO_BED_LEVELING_UBL)
    #include "ubl/ubl.h"
  #elif ENABLED(MESH_BED_LEVELING)
    #include "mbl/mesh_bed_leveling.h"
  #endif

  #define Z_VALUES(X,Y) Z_VALUES_ARR[X][Y]
  #define _GET_MESH_POS(M) { _GET_MESH_X(M.a), _GET_MESH_Y(M.b) }

  #if EITHER(AUTO_BED_LEVELING_BILINEAR, MESH_BED_LEVELING)

    #include <stdint.h>

    typedef float (*element_2d_fn)(const uint8_t, const uint8_t);

    /**
     * Print calibration results for plotting or manual frame adjustment.
     */
    void print_2d_array(const uint8_t sx, const uint8_t sy, const uint8_t precision, element_2d_fn fn);

  #endif

  struct mesh_index_pair {
    xy_int8_t pos;
    float distance;   // When populated, the distance from the search location
    void invalidate() { pos = -1; }
    bool valid() const { return pos.x >= 0 && pos.y >= 0; }
    #if ENABLED(AUTO_BED_LEVELING_UBL)
      xy_pos_t meshpos() {
        return { ubl.mesh_index_to_xpos(pos.x), ubl.mesh_index_to_ypos(pos.y) };
      }
    #endif
    operator xy_int8_t&() { return pos; }
    operator const xy_int8_t&() const { return pos; }
  };

#endif
