#include "../../inc/constant.h"
#include "../../inc/types.h"
#include "../../inc/operation.h"

void	set_pixel_center(t_window *window, t_point *pixel_center, int x, int y)
{
	*pixel_center = add_point(multiply_point(window->pixel_delta[U].dir, x),
							  multiply_point(window->pixel_delta[V].dir, y));
	*pixel_center = add_point(*pixel_center, window->pixel00_loc);
}