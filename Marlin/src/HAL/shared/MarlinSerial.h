#pragma once

/**
 * HAL/shared/MarlinSerial.h
 */

#include "../../inc/MarlinConfigPre.h"

constexpr bool
  #if HAS_DGUS_LCD
    bDGUS_SERIAL_STATS_RX_BUFFER_OVERRUNS = (false
      #if ENABLED(DGUS_SERIAL_STATS_RX_BUFFER_OVERRUNS)
        || true
      #endif
    ),
  #endif
  bSERIAL_XON_XOFF = (false
    #if ENABLED(SERIAL_XON_XOFF)
      || true
    #endif
  ),
  bEMERGENCY_PARSER = (false
    #if ENABLED(EMERGENCY_PARSER)
      || true
    #endif
  ),
  bSERIAL_STATS_DROPPED_RX = (false
    #if ENABLED(SERIAL_STATS_DROPPED_RX)
      || true
    #endif
  ),
  bSERIAL_STATS_RX_BUFFER_OVERRUNS = (false
    #if ENABLED(SERIAL_STATS_RX_BUFFER_OVERRUNS)
      || true
    #endif
  ),
  bSERIAL_STATS_RX_FRAMING_ERRORS = (false
    #if ENABLED(SERIAL_STATS_RX_FRAMING_ERRORS)
      || true
    #endif
  ),
  bSERIAL_STATS_MAX_RX_QUEUED = (false
    #if ENABLED(SERIAL_STATS_MAX_RX_QUEUED)
      || true
    #endif
  );
