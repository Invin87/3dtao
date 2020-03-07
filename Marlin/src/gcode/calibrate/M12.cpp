#include "../../inc/MarlinConfigPre.h"

#if ENABLED(EXTERNAL_CLOSED_LOOP_CONTROLLER)

#include "../gcode.h"
#include "../../module/planner.h"
#include "../../feature/closedloop.h"

void GcodeSuite::M12() {
  planner.synchronize();
  if (parser.seenval('S'))
    set_closedloop(parser.value_int()); // Force a CLC set
}

#endif
