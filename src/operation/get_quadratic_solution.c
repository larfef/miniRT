#include "../inc/types.h"
#include <math.h>

float get_quadratic_solution(t_quadratic *params)
{
	params->t1 = (float)(-(params->h) - sqrt(params->discriminant)) / params->a;
	params->t2 = (float)(-(params->h) + sqrt(params->discriminant)) / params->a;
	if (params->t1 > 0 && params->t2 > 0)
		return ((float)fmin((float)params->t1, (float)params->t2));
	else if (params->t1 > 0)
		return params->t1;
	else if (params->t2 > 0)
		return params->t2;
	return -1.0f;
}
