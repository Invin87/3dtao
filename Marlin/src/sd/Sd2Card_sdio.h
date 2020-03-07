#pragma once

#include "../inc/MarlinConfig.h"

#if ENABLED(SDIO_SUPPORT)

bool SDIO_Init();
bool SDIO_ReadBlock(uint32_t block, uint8_t *dst);
bool SDIO_WriteBlock(uint32_t block, const uint8_t *src);

class Sd2Card {
  public:
    bool init(uint8_t sckRateID = 0, uint8_t chipSelectPin = 0) { return SDIO_Init(); }
    bool readBlock(uint32_t block, uint8_t *dst) { return SDIO_ReadBlock(block, dst); }
    bool writeBlock(uint32_t block, const uint8_t *src) { return SDIO_WriteBlock(block, src); }
};

#endif // SDIO_SUPPORT
