#include "../../inc/types.h"
#include "../../inc/operation.h"

/*
	@dev: Give the camera up direction axis;
	@param w: normalized 3d camera orientation vector;
*/

t_vector	get_vup(t_vector *w)
{
	t_vector	vup = {0};
	t_vector	tmp;

	vup.dir.y = 1;
	tmp = cross_product(vup, *w);
	if (length(tmp) < 1e-6)
		vup.dir = (t_point){1, 0, 0};
	normalize(&vup);
	return (vup);
}
