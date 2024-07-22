#include "../../inc/types.h"

t_point	multiply_point(t_point *a, float n)
{
	t_point	result;

	result.x = a->x * n;
	result.y = a->y * n;
	result.z = a->z * n;
	return (result);
}
