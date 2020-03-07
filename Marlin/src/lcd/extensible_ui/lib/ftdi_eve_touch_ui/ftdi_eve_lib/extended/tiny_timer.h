/****************
 * tiny_timer.h *
 ****************/

#pragma once

/* Helpful Reference:
 *
 *  https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 */

/* tiny_interval_t downsamples a 32-bit millis() value
   into a 8-bit value which can record periods of
   a few seconds with a rougly 1/16th of second
   resolution. This allows us to measure small
   intervals without needing to use four-byte counters.
 */
class tiny_time_t {
  private:
    friend class tiny_timer_t;
    uint8_t _duration;

    static uint8_t tiny_time(uint32_t ms) {return ceil(float(ms) / 64);};

  public:
    tiny_time_t()            : _duration(0) {}
    tiny_time_t(uint32_t ms) : _duration(tiny_time(ms)) {}
    tiny_time_t & operator=   (uint32_t ms) {_duration = tiny_time(ms); return *this;}
    bool          operator == (uint32_t ms) {return _duration == tiny_time(ms);}
};

class tiny_timer_t {
  private:
    uint8_t _start;

  public:
    void start();
    bool elapsed(tiny_time_t interval);
};
