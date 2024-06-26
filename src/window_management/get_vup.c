#include "../../inc/rendering.h"
#include "../../inc/window_management.h"
#include "math.h"

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
	vup = unit_vector(&vup);
//	if (vup.x == -0.0f) vup.x = 0.0f;
//	if (vup.y == -0.0f) vup.y = 0.0f;
//	if (vup.z == -0.0f) vup.z = 0.0f;
	return (vup);
}
