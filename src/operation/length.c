#include "../../inc/types.h"
#include "../../inc/operation.h"
#include <math.h>

/*
	@dev: return the length of a given vector
 	@param: a: vector struct
*/

float	length(t_vector a)
{
	return (sqrt(dot_product(a, a)));
}
