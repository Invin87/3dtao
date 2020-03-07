/**************
 * dl_cache.h *
 **************/

#pragma once

/******************* DISPLAY LIST CACHE MANAGEMENT ************************/
/* The Display List Cache mechanism stores the display list corresponding
 * to a menu into RAM_G so that on subsequent calls drawing the menu does
 * not require as much SPI traffic. Dynamic content, such as indicators,
 * should not be cached.
 *
 * The DLCache can be used like so:
 *
 *   void some_function() {
 *     DLCache dlcache(UNIQUE_ID);
 *
 *     if (dlcache.hasData()) {
 *        dlcache.append();
 *     } else {
 *        // Add stuff to the DL
 *        dlcache.store();
 *     }
 */
class DLCache {
  private:
    typedef FTDI::ftdi_registers  REG;
    typedef FTDI::ftdi_memory_map MAP;

    uint8_t  dl_slot;
    uint32_t dl_addr;
    uint16_t dl_size;

    void load_slot();
    static void save_slot(uint8_t dl_slot, uint32_t dl_addr, uint32_t dl_size);

    bool wait_until_idle();

  public:
    static void init();

    DLCache(uint8_t slot) {
      dl_slot = slot;
      load_slot();
    }

    bool has_data();
    bool store(uint32_t num_bytes = 0);
    void append();
};

#define DL_CACHE_SLOTS   250
