
#include "../inc/MarlinConfig.h"

#if ENABLED(MK2_MULTIPLEXER)

#include "../module/stepper.h"

void select_multiplexed_stepper(const uint8_t e) {
  planner.synchronize();
  disable_e_steppers();
  WRITE(E_MUX0_PIN, TEST(e, 0) ? HIGH : LOW);
  WRITE(E_MUX1_PIN, TEST(e, 1) ? HIGH : LOW);
  WRITE(E_MUX2_PIN, TEST(e, 2) ? HIGH : LOW);
  safe_delay(100);
}

#endif // MK2_MULTIPLEXER
