#pragma once

#include "../../shared/HAL_SPI.h"

#include <stdint.h>

#define MSBFIRST 1
#define SPI_MODE3 0

class SPISettings {
  public:
    SPISettings(uint32_t speed, int, int) : spi_speed(speed) {};
    uint32_t spiRate() { return spi_speed; }
  private:
    uint32_t spi_speed;
};

class SPIClass {
  public:
    void begin();
    void beginTransaction(SPISettings);
    void endTransaction() {};
    uint8_t transfer(uint8_t data);
    uint16_t transfer16(uint16_t data);
};

extern SPIClass SPI;
