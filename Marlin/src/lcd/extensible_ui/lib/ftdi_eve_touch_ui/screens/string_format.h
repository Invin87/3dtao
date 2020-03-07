/*******************
 * string_format.h *
 *******************/

#pragma once

void format_temp(char *str, float t1);
void format_temp_and_idle(char *str, float t1);
void format_temp_and_temp(char *str, float t1, float t2);
void format_temp_and_material(char *str, float t1, const char *material);
void format_position(char *str, float p);
void format_position(char *str, float x, float y, float z);
