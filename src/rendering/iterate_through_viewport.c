#include "../../inc/types.h"
#include "../../inc/rendering.h"
#include "../../inc/window_management.h"
#include "../../inc/operation.h"
#include "../mlx/mlx.h"
#include "../libft/inc/libft.h"
#include <stdio.h>

void progress_bar(int y, int height)
{
	int32_t progress;
	int32_t bar_width = 50;
	int32_t pos;
	char bar[bar_width + 1]; // Plus one for the null terminator

	progress = ((y * 100) / height);
	pos = (bar_width * progress) / 100;

	ft_memset(bar, '=', pos);
	ft_memset(bar + pos, ' ', bar_width - pos);
	bar[bar_width] = '\0'; // Null terminator for the string

	printf("\rProgress: [%s] %d%%", bar, progress);
	write(1, "\r", 1);
}

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
			mlx_pixel_put(window->mlx, window->window, x, y, (int)raytracer->color.color);
		}
		// progress_bar(y, window->height);
		x = -1;
	}
	printf("\n");
}
