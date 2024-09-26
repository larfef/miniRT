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

void	iterate_through_viewport(t_window *win, t_scene *scene, t_ray_tracing *rt)
{
	rt->camera_to_viewport.origin = scene->camera.coordinates;
	while (++win->window_y != win->height)
	{
		while (++win->window_x != win->width)
		{
			set_pixel_center(win, &rt->pixel_center, x, y);
			rt->camera_to_viewport.dir = sub_point(rt->pixel_center, scene->camera.coordinates);
			iterate_through_shapes_list(scene, rt);
			trace_rays(scene, rt);
			mlx_pixel_put(win->mlx, win->window, x, y, rt->color.color);
		}
		 progress_bar(y, win->height);
		win->window_x = -1;
	}
	printf("\n");
}
