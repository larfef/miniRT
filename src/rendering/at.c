#include "../../inc/rendering.h"

t_vector	at(t_ray *ray, float t)
{
	t_vector	result;

	result = multiply_vector(ray->dir, t);
	result = add_vector(ray->origin, result);
	return (result);
}
