#include "../../inc/types.h"

t_point	add_point(t_point *a, t_point *b)
{
	t_point	result;

	result.x = a->x + b->x;
	result.y = a->y + b->y;
	result.z = a->z + b->z;
	return (result);
}
