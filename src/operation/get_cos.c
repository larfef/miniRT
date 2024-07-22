#include "../../inc/operation.h"

/*
	@dev: get cosinus value of the smallest angle between two vectors
 	@param: a: vector pointer
 	@param: b: vector pointer
*/

float	get_cos(t_vector *a, t_vector *b)
{
	float	len_a;
	float	len_b;
	float	product;
	float	result;

	len_a = length(a);
	len_b = length(b);
	product = dot_product(a, b);
	result = product / (len_a * len_b);
	return (result);
}
