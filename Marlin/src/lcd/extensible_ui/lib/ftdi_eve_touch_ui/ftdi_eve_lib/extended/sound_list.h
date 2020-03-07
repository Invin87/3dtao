/****************
 * sound_list.h *
 ****************/

#pragma once

class SoundList {
  private:
    static PROGMEM const struct list_t {
      const char *const PROGMEM name;
      const FTDI::SoundPlayer::sound_t* data;
    } list[];
  public:
    static const uint8_t n;
    static inline const char* name(uint8_t val) {
      return (const char* ) pgm_read_ptr_near(&list[val].name);
    }
    static inline FTDI::SoundPlayer::sound_t* data(uint8_t val) {
      return (FTDI::SoundPlayer::sound_t*) pgm_read_ptr_near(&list[val].data);
    }
};
