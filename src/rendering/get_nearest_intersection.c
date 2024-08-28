#include "../../inc/types.h"
#include <unistd.h>
void	get_nearest_intersection(intersection_t *fct_ptr_array, t_shapes *shape, t_ray_tracing *raytracer)
{
	float 		ret;

	ret = fct_ptr_array[shape->type](shape, &raytracer->camera_to_viewport);
	if (ret == -1.0f)
		return ;
	if (!raytracer->solution
		|| ret < raytracer->solution)
	{
		raytracer->solution = ret;
		raytracer->shape = shape;
	}
}
