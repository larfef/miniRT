#include "../../inc/operation.h"

t_vector	at(t_vector *ray, float t)
{
	t_vector	result;

	result = multiply_vector(*ray, t);
	result = add_vector(*ray, result);
	return (result);
}
