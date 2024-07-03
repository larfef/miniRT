#include "../../inc/rendering.h"
#include "../../inc/window_management.h"
#include "math.h"

/*
	Give the camera up direction axis;
	@param w: normalized orientation vector;
*/

t_vector	get_vup(t_vector *w)
{
	t_vector	vup = {0.0, 1.0, 0.0};
	t_vector	tmp;

	tmp = cross_product(&vup, w);
	if (length(&tmp) < 1e-6)
		vup = (t_vector){1.0, 0.0, 0.0};
	vup = unit_vector(&vup);
	return (vup);
}
