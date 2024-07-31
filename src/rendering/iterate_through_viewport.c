#include "../../inc/types.h"
#include "../../inc/rendering.h"
#include "../../inc/window_management.h"
#include "../../inc/operation.h"
#include "../mlx/mlx.h"

void	iterate_through_viewport(t_window *window, t_scene *scene, t_ray_tracing *raytracer)
{
	int32_t		x;
	int32_t		y;

	x = -1;
	y = -1;
	raytracer->camera_to_viewport.origin = scene->camera.coordinates;
	while (++y != window->height)
	{
		while (++x != window->width)
		{
			set_pixel_center(window, &raytracer->pixel_center, x, y);
			raytracer->camera_to_viewport.dir = sub_point(raytracer->pixel_center, scene->camera.coordinates);
			iterate_through_shapes_list(scene, raytracer);
			trace_rays(scene, raytracer);
			mlx_pixel_put(window->mlx, window->window, x, y, raytracer->color.color);
		}
		x = -1;
	}
}
