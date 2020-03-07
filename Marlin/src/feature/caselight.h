#pragma once

extern uint8_t case_light_brightness;
extern bool case_light_on;
extern uint8_t case_light_brightness_sav;   // saves brighness info when case_light_on is false
extern bool case_light_arg_flag;  // flag to notify if S or P argument type

void update_case_light();
