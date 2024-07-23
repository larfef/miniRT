#include "../../inc/window_management.h"
#include "../../inc/rendering.h"

t_point	pixel00_loc(t_vector (*pixel_delta)[2], t_point viewport_upper_left)
{
	t_point	pixel00_loc;

	pixel00_loc = add_vector((*pixel_delta)[U], (*pixel_delta[V]));
	pixel00_loc = multiply_vector(pixel00_loc, 0.5);
	pixel00_loc = add_vector(viewport_upper_left, pixel00_loc);
	return (pixel00_loc);
}
