
/**
 * HAL for stm32duino.com based on Libmaple and compatible (STM32F1)
 * Implementation of EEPROM settings in SD Card
 */

#ifdef __STM32F1__

#include "../../inc/MarlinConfig.h"

#if ENABLED(EEPROM_SETTINGS) && NONE(FLASH_EEPROM_EMULATION, SPI_EEPROM, I2C_EEPROM)

#include "../shared/persistent_store_api.h"

#ifndef E2END
  #define E2END 0xFFF // 4KB
#endif
#define HAL_EEPROM_SIZE (E2END + 1)

#define _ALIGN(x) __attribute__ ((aligned(x))) // SDIO uint32_t* compat.
static char _ALIGN(4) HAL_eeprom_data[HAL_EEPROM_SIZE];

#if ENABLED(SDSUPPORT)

  #include "../../sd/cardreader.h"

  #define EEPROM_FILENAME "eeprom.dat"

  bool PersistentStore::access_start() {
    if (!card.isMounted()) return false;

    SdFile file, root = card.getroot();
    if (!file.open(&root, EEPROM_FILENAME, O_RDONLY))
      return true; // false aborts the save

    int bytes_read = file.read(HAL_eeprom_data, HAL_EEPROM_SIZE);
    if (bytes_read < 0) return false;
    for (; bytes_read < HAL_EEPROM_SIZE; bytes_read++)
      HAL_eeprom_data[bytes_read] = 0xFF;
    file.close();
    return true;
  }

  bool PersistentStore::access_finish() {
    if (!card.isMounted()) return false;

    SdFile file, root = card.getroot();
    int bytes_written = 0;
    if (file.open(&root, EEPROM_FILENAME, O_CREAT | O_WRITE | O_TRUNC)) {
      bytes_written = file.write(HAL_eeprom_data, HAL_EEPROM_SIZE);
      file.close();
    }
    return (bytes_written == HAL_EEPROM_SIZE);
  }

#else // !SDSUPPORT

  #error "Please define SPI_EEPROM (in Configuration.h) or disable EEPROM_SETTINGS."

#endif // !SDSUPPORT

bool PersistentStore::write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc) {
  for (size_t i = 0; i < size; i++)
    HAL_eeprom_data[pos + i] = value[i];
  crc16(crc, value, size);
  pos += size;
  return false;
}

bool PersistentStore::read_data(int &pos, uint8_t* value, const size_t size, uint16_t *crc, const bool writing/*=true*/) {
  for (size_t i = 0; i < size; i++) {
    uint8_t c = HAL_eeprom_data[pos + i];
    if (writing) value[i] = c;
    crc16(crc, &c, 1);
  }
  pos += size;
  return false;
}

size_t PersistentStore::capacity() { return HAL_EEPROM_SIZE; }

#endif // EEPROM_SETTINGS

#endif // __STM32F1__
