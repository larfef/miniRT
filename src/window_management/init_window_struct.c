#include "../inc/init_stack.h"
#include "../inc/window_management.h"
#include "../inc/operation.h"
#include "../libft/inc/libft.h"

void	init_window_struct(t_scene *scene, t_window *win)
{
	ft_memset(win, '\0', sizeof(*win));
	win->width = IMAGE_WIDTH;
	win->aspect_ratio = (float)WIDTH_RATIO / HEIGHT_RATIO;
	set_window_height((float)win->width, win->aspect_ratio, &win->height);
	set_viewport(win->width, win->height, &win->viewport, scene->camera.fov);
	set_viewport_vectors(&win->viewport, &win->viewport_vectors,
						 &scene->camera.orientation);
	set_pixel_delta(win->width, win->height, &win->viewport_vectors,
					&win->pixel_delta);
	set_upper_left_pixel(scene->camera.coordinates,
						 &win->viewport_vectors, scene->camera.orientation,
						 &win->viewport_upper_left);
	set_pixel00_loc(&win->pixel_delta, win->viewport_upper_left,
					&win->pixel00_loc);
}
