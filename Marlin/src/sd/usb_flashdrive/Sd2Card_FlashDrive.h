#pragma once

/**
 * \file
 * \brief Sd2Card class for V2 SD/SDHC cards
 */

#include "../SdFatConfig.h"
#include "../SdInfo.h"

/**
 * define SOFTWARE_SPI to use bit-bang SPI
 */
#if MEGA_SOFT_SPI || USE_SOFTWARE_SPI
  #define SOFTWARE_SPI
#endif

// SPI pin definitions - do not edit here - change in SdFatConfig.h
#if DISABLED(SOFTWARE_SPI)
  // hardware pin defs
  #define SD_CHIP_SELECT_PIN  SS_PIN            // The default chip select pin for the SD card is SS.
#else  // SOFTWARE_SPI
  #define SD_CHIP_SELECT_PIN  10                // Software SPI chip select pin for the SD
#endif // SOFTWARE_SPI

class Sd2Card {
  private:
    uint32_t pos;

    static void usbStateDebug();

  public:
    static bool usbStartup();

    bool init(const uint8_t sckRateID=0, const pin_t chipSelectPin=SD_CHIP_SELECT_PIN);

    static void idle();

    inline bool readStart(const uint32_t block)                  { pos = block; return ready(); }
    inline bool readData(uint8_t* dst)                           { return readBlock(pos++, dst); }
    inline bool readStop() const                                 { return true; }

    inline bool writeStart(const uint32_t block, const uint32_t) { pos = block; return ready(); }
    inline bool writeData(uint8_t* src)                          { return writeBlock(pos++, src); }
    inline bool writeStop() const                                { return true; }

    bool readBlock(uint32_t block, uint8_t* dst);
    bool writeBlock(uint32_t blockNumber, const uint8_t* src);

    uint32_t cardSize();
    static bool isInserted();
    static bool ready();
};
