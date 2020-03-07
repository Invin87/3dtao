#pragma once

/**
 * scara.h - SCARA-specific functions
 */

#include "../core/macros.h"

extern float delta_segments_per_second;

// Float constants for SCARA calculations
float constexpr L1 = SCARA_LINKAGE_1, L2 = SCARA_LINKAGE_2,
                L1_2 = sq(float(L1)), L1_2_2 = 2.0 * L1_2,
                L2_2 = sq(float(L2));

void scara_set_axis_is_at_home(const AxisEnum axis);

void inverse_kinematics(const xyz_pos_t &raw);
void forward_kinematics_SCARA(const float &a, const float &b);

void scara_report_positions();
