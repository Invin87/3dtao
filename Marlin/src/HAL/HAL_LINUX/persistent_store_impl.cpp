
#ifdef __PLAT_LINUX__

#include "../../inc/MarlinConfig.h"

#if ENABLED(EEPROM_SETTINGS)

#include "../shared/persistent_store_api.h"
#include <stdio.h>

#define LINUX_EEPROM_SIZE (E2END + 1)
uint8_t buffer[LINUX_EEPROM_SIZE];
char filename[] = "eeprom.dat";

bool PersistentStore::access_start() {
  const char eeprom_erase_value = 0xFF;
  FILE * eeprom_file = fopen(filename, "rb");
  if (eeprom_file == nullptr) return false;

  fseek(eeprom_file, 0L, SEEK_END);
  std::size_t file_size = ftell(eeprom_file);

  if (file_size < LINUX_EEPROM_SIZE) {
    memset(buffer + file_size, eeprom_erase_value, LINUX_EEPROM_SIZE - file_size);
  }
  else {
    fseek(eeprom_file, 0L, SEEK_SET);
    fread(buffer, sizeof(uint8_t), sizeof(buffer), eeprom_file);
  }

  fclose(eeprom_file);
  return true;
}

bool PersistentStore::access_finish() {
  FILE * eeprom_file = fopen(filename, "wb");
  if (eeprom_file == nullptr) return false;
  fwrite(buffer, sizeof(uint8_t), sizeof(buffer), eeprom_file);
  fclose(eeprom_file);
  return true;
}

bool PersistentStore::write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc) {
  std::size_t bytes_written = 0;

  for (std::size_t i = 0; i < size; i++) {
    buffer[pos+i] = value[i];
    bytes_written ++;
  }

  crc16(crc, value, size);
  pos = pos + size;
  return (bytes_written != size);  // return true for any error
}

bool PersistentStore::read_data(int &pos, uint8_t* value, const size_t size, uint16_t *crc, const bool writing/*=true*/) {
  std::size_t bytes_read = 0;
  if (writing) {
    for (std::size_t i = 0; i < size; i++) {
      value[i] = buffer[pos+i];
      bytes_read ++;
    }
    crc16(crc, value, size);
  }
  else {
    uint8_t temp[size];
    for (std::size_t i = 0; i < size; i++) {
      temp[i] = buffer[pos+i];
      bytes_read ++;
    }
    crc16(crc, temp, size);
  }

  pos = pos + size;
  return bytes_read != size;  // return true for any error
}

size_t PersistentStore::capacity() { return 4096; } // 4KiB of Emulated EEPROM

#endif // EEPROM_SETTINGS
#endif // __PLAT_LINUX__
