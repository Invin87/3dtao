
/**
 * printer_event_leds.cpp - LED color changing based on printer status
 */

#include "../../inc/MarlinConfigPre.h"

#if ENABLED(PRINTER_EVENT_LEDS)

#include "printer_event_leds.h"

PrinterEventLEDs printerEventLEDs;

#if HAS_LEDS_OFF_FLAG
  bool PrinterEventLEDs::leds_off_after_print; // = false
#endif

#if HAS_TEMP_HOTEND || HAS_HEATED_BED

  uint8_t PrinterEventLEDs::old_intensity = 0;

  inline uint8_t pel_intensity(const float &start, const float &current, const float &target) {
    return (uint8_t)map(constrain(current, start, target), start, target, 0.f, 255.f);
  }

  inline void pel_set_rgb(const uint8_t r, const uint8_t g, const uint8_t b) {
    leds.set_color(
      MakeLEDColor(r, g, b, 0, neo.brightness())
        #if ENABLED(NEOPIXEL_IS_SEQUENTIAL)
          , true
        #endif
      );
  }

#endif

#if HAS_TEMP_HOTEND

  void PrinterEventLEDs::onHotendHeating(const float &start, const float &current, const float &target) {
    const uint8_t blue = pel_intensity(start, current, target);
    if (blue != old_intensity) {
      old_intensity = blue;
      pel_set_rgb(255, 0, 255 - blue);
    }
  }

#endif

#if HAS_HEATED_BED

  void PrinterEventLEDs::onBedHeating(const float &start, const float &current, const float &target) {
    const uint8_t red = pel_intensity(start, current, target);
    if (red != old_intensity) {
      old_intensity = red;
      pel_set_rgb(red, 0, 255);
    }
  }
#endif

#endif // PRINTER_EVENT_LEDS
