#include "../../inc/rendering.h"
#include "../../inc/window_management.h"

/*
	Give the camera up direction axis;
	@param w: normalized orientation vector;
*/

t_vector	get_vup(t_vector *w)
{
	t_vector	world_up = {0.0, 1.0, 0.0};
	t_vector	vup = cross_product(w, &world_up);

	if (length(&vup) < 1e-6)
	{
		world_up = (t_vector){1.0, 0.0, 0.0};
		vup = cross_product(w, &world_up);
	}
	return (unit_vector(&vup));
}
