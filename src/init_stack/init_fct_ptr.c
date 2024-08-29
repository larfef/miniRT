#include "../../inc/types.h"
#include "../../inc/rendering.h"

void	init_fct_ptr(t_scene *ptr)
{
	ptr->intersection[0] = cylinder_intersection;
	ptr->intersection[1] = plane_intersection;
	ptr->intersection[2] = sphere_intersection;
}