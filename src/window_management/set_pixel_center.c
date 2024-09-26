#include "../../inc/constant.h"
#include "../../inc/types.h"
#include "../../inc/operation.h"

/*
	@dev:	Set the current pixel center.
			This value is used to compute the camera to viewport vector direction.
	@param:	win: window structure containing variables related to the window
			management.
			pixel_delta: distance between each pixel.
			x,y : current pixel coordinates.
			pixel00_loc: location of the upper left pixel.
*/

void	set_pixel_center(t_window *win, t_point *pixel_center)
{
	*pixel_center = add_point(multiply_point(win->pixel_delta[U].dir, win->x),
							  multiply_point(win->pixel_delta[V].dir, win->y));
	*pixel_center = add_point(*pixel_center, win->pixel00_loc);
}
