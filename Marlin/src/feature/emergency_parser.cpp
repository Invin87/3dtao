
/**
 * emergency_parser.cpp - Intercept special commands directly in the serial stream
 */

#include "../inc/MarlinConfigPre.h"

#if ENABLED(EMERGENCY_PARSER)

#include "emergency_parser.h"

// Static data members
bool EmergencyParser::killed_by_M112, // = false
     EmergencyParser::enabled;

#if ENABLED(HOST_PROMPT_SUPPORT)
  uint8_t EmergencyParser::M876_reason; // = 0
#endif

// Global instance
EmergencyParser emergency_parser;

#endif // EMERGENCY_PARSER
