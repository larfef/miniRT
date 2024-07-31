#include "../inc/operation.h"

void	get_discriminant(t_vector *ray, t_vector oc, float radius, t_quadratic *params)
{
	params->a = dot_product(*ray, *ray);
	params->h = dot_product(*ray, oc);
	params->c  = dot_product(oc, oc) - (radius * radius);
	params->discriminant = (params->h * params->h) - (params->a * params->c);
}
