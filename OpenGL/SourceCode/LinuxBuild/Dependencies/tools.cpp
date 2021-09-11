#include "tools.h"

float map(float target_min, float target_max, float input_min, float input_max, float input_value)
{
    float input_Span = input_max - input_min;
    float target_Span = target_max - target_min;

    float valueScaled = (float) (input_value - input_min) / (float) (input_Span);

    return target_min + (valueScaled * target_Span);
}

float deg_to_radian(float deg)
{
	return deg * (pi/180);
}
