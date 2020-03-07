#include "../../inc/MarlinConfig.h"

#if ENABLED(HOST_PROMPT_SUPPORT) && DISABLED(EMERGENCY_PARSER)

#include "../../feature/host_actions.h"
#include "../gcode.h"
#include "../../MarlinCore.h"

/**
 * M876: Handle Prompt Response
 */
void GcodeSuite::M876() {

  if (parser.seenval('S')) host_response_handler((uint8_t)parser.value_int());

}

#endif // HOST_PROMPT_SUPPORT && !EMERGENCY_PARSER
