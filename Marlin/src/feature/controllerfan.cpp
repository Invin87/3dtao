
#include "../inc/MarlinConfig.h"

#if ENABLED(USE_CONTROLLER_FAN)

#include "../module/stepper/indirection.h"
#include "../module/temperature.h"

uint8_t controllerfan_speed;

void controllerfan_update() {
  static millis_t lastMotorOn = 0, // Last time a motor was turned on
                  nextMotorCheck = 0; // Last time the state was checked
  const millis_t ms = millis();
  if (ELAPSED(ms, nextMotorCheck)) {
    nextMotorCheck = ms + 2500UL; // Not a time critical function, so only check every 2.5s

    const bool xory = X_ENABLE_READ() == bool(X_ENABLE_ON) || Y_ENABLE_READ() == bool(Y_ENABLE_ON);

    // If any of the drivers or the bed are enabled...
    if (xory || Z_ENABLE_READ() == bool(Z_ENABLE_ON)
      #if HAS_HEATED_BED
        || thermalManager.temp_bed.soft_pwm_amount > 0
      #endif
      #if HAS_X2_ENABLE
        || X2_ENABLE_READ() == bool(X_ENABLE_ON)
      #endif
      #if HAS_Y2_ENABLE
        || Y2_ENABLE_READ() == bool(Y_ENABLE_ON)
      #endif
      #if HAS_Z2_ENABLE
        || Z2_ENABLE_READ() == bool(Z_ENABLE_ON)
      #endif
      #if HAS_Z3_ENABLE
        || Z3_ENABLE_READ() == bool(Z_ENABLE_ON)
      #endif
      #if HAS_Z4_ENABLE
        || Z4_ENABLE_READ() == bool(Z_ENABLE_ON)
      #endif
      #if E_STEPPERS
        #define _OR_ENABLED_E(N) || E##N##_ENABLE_READ() == bool(E_ENABLE_ON)
        REPEAT(E_STEPPERS, _OR_ENABLED_E)
      #endif
    ) {
      lastMotorOn = ms; //... set time to NOW so the fan will turn on
    }

    // Fan off if no steppers have been enabled for CONTROLLERFAN_SECS seconds
    controllerfan_speed = (!lastMotorOn || ELAPSED(ms, lastMotorOn + (CONTROLLERFAN_SECS) * 1000UL)) ? 0 : (
      #ifdef CONTROLLERFAN_SPEED_Z_ONLY
        xory ? CONTROLLERFAN_SPEED : CONTROLLERFAN_SPEED_Z_ONLY
      #else
        CONTROLLERFAN_SPEED
      #endif
    );

    // Allow digital or PWM fan output (see M42 handling)
    WRITE(CONTROLLER_FAN_PIN, controllerfan_speed);
    analogWrite(pin_t(CONTROLLER_FAN_PIN), controllerfan_speed);
  }
}

#endif // USE_CONTROLLER_FAN
