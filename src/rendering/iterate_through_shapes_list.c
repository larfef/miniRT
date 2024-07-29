#include "../../inc/types.h"
#include "../../inc/rendering.h"

void	iterate_through_shapes_list(t_window *window, t_scene *scene, t_ray_tracing *raytracer)
{
	t_shapes *shape;

	shape = scene->shapes;
	raytracer->solution =  0.0f;
	while (shape)
	{
		get_nearest_intersection(scene->intersection, shape, raytracer);
		shape = shape->next;
	}
	//color calculation logic
}
