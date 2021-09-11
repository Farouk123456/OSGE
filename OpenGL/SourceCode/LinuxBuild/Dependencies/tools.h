#pragma once
#include <cmath>

const double pi = 3.141592;
const double phi = (1 + sqrt(5)) / 2;

float map(float target_min, float target_max, float input_min, float input_max, float input_value);

float deg_to_radian(float deg);
