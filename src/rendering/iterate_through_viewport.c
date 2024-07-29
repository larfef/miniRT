#include "../../inc/types.h"
#include "../../inc/rendering.h"

void	iterate_through_viewport(t_window *window, t_scene *scene, t_ray_tracing *raytracer)
{
	int32_t		x;
	int32_t		y;

	x = -1;
	y = -1;
	while (++y != window->height)
	{
		while (++x != window->width)
		{
			set_pixel_center(window, &raytracer->pixel_center, x, y);
			raytracer->camera_to_viewport.dir = sub_point(raytracer->pixel_center, scene->camera.coordinates);
			iterate_through_shapes_list(window, scene, raytracer);
		}
		x = -1;
	}
}