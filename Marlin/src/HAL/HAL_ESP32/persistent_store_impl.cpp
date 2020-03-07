
#ifdef ARDUINO_ARCH_ESP32

#include "../../inc/MarlinConfig.h"

#if ENABLED(EEPROM_SETTINGS) && DISABLED(FLASH_EEPROM_EMULATION)

#include "../shared/persistent_store_api.h"
#include "EEPROM.h"

#define EEPROM_SIZE 4096

bool PersistentStore::access_start() {
  return EEPROM.begin(EEPROM_SIZE);
}

bool PersistentStore::access_finish() {
  EEPROM.end();
  return true;
}

bool PersistentStore::write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc) {
  for (size_t i = 0; i < size; i++) {
    EEPROM.write(pos++, value[i]);
    crc16(crc, &value[i], 1);
  }
  return false;
}

bool PersistentStore::read_data(int &pos, uint8_t* value, size_t size, uint16_t *crc, const bool writing/*=true*/) {
  for (size_t i = 0; i < size; i++) {
    uint8_t c = EEPROM.read(pos++);
    if (writing) value[i] = c;
    crc16(crc, &c, 1);
  }
  return false;
}

size_t PersistentStore::capacity() { return EEPROM_SIZE; }

#endif // EEPROM_SETTINGS
#endif // ARDUINO_ARCH_ESP32
