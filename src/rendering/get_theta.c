#include "../../inc/rendering.h"

float	get_theta(t_vector *a, t_vector *b)
{
	float	len_a;
	float	len_b;
	float	product;

	len_a = length(a);
	len_b = length(b);
	product = dot_product(a, b);
	return (product / (len_a * len_b));
}
