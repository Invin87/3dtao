
#include "../inc/MarlinConfig.h"

#if HAS_CASE_LIGHT

uint8_t case_light_brightness = CASE_LIGHT_DEFAULT_BRIGHTNESS;
bool case_light_on = CASE_LIGHT_DEFAULT_ON;

#if ENABLED(CASE_LIGHT_USE_NEOPIXEL)
  #include "leds/leds.h"
  LEDColor case_light_color =
    #ifdef CASE_LIGHT_NEOPIXEL_COLOR
      CASE_LIGHT_NEOPIXEL_COLOR
    #else
      { 255, 255, 255, 255 }
    #endif
  ;
#endif

/**
 * The following are needed because ARM chips ignore a "WRITE(CASE_LIGHT_PIN,x)" command to the pins that
 * are directly controlled by the PWM module. In order to turn them off the brightness level needs to be
 * set to off.  Since we can't use the pwm register to save the last brightness level we need a variable
 * to save it.
 */
uint8_t case_light_brightness_sav;   // saves brighness info so can restore when "M355 S1" received
bool case_light_arg_flag;  // flag to notify if S or P argument type

#ifndef INVERT_CASE_LIGHT
  #define INVERT_CASE_LIGHT false
#endif

void update_case_light() {

  if (!(case_light_arg_flag && !case_light_on))
    case_light_brightness_sav = case_light_brightness;  // save brightness except if this is an S0 argument
  if (case_light_arg_flag && case_light_on)
    case_light_brightness = case_light_brightness_sav;  // restore last brightens if this is an S1 argument

  #if ENABLED(CASE_LIGHT_USE_NEOPIXEL) || DISABLED(CASE_LIGHT_NO_BRIGHTNESS)
    const uint8_t i = case_light_on ? case_light_brightness : 0, n10ct = INVERT_CASE_LIGHT ? 255 - i : i;
  #endif

  #if ENABLED(CASE_LIGHT_USE_NEOPIXEL)

    leds.set_color(
      MakeLEDColor(case_light_color.r, case_light_color.g, case_light_color.b, case_light_color.w, n10ct),
      false
    );

  #else // !CASE_LIGHT_USE_NEOPIXEL

    #if DISABLED(CASE_LIGHT_NO_BRIGHTNESS)
      if (PWM_PIN(CASE_LIGHT_PIN))
        analogWrite(pin_t(CASE_LIGHT_PIN), (
          #if CASE_LIGHT_MAX_PWM == 255
            n10ct
          #else
            map(n10ct, 0, 255, 0, CASE_LIGHT_MAX_PWM)
          #endif
        ));
      else
    #endif
      {
        const bool s = case_light_on ? !INVERT_CASE_LIGHT : INVERT_CASE_LIGHT;
        WRITE(CASE_LIGHT_PIN, s ? HIGH : LOW);
      }

  #endif // !CASE_LIGHT_USE_NEOPIXEL
}

#endif // HAS_CASE_LIGHT
