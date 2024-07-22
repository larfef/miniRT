#include "../../inc/rendering.h"

float	get_sin(t_vector *a, t_vector *b)
{
	t_vector	cross;
	float		len_a;
	float		len_b;
	float		len_cross;

	cross = cross_product(a, b);
	len_cross = length(&cross);
	len_a = length(a);
	len_b = length(b);
	return (len_cross / (len_a * len_b));
}
