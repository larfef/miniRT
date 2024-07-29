#include "../../inc/window_management.h"
#include "../../inc/operation.h"

/*
	@dev: return the viewport upper left pixel center location
 	@param: pixel_delta: array of vectors representing the distance between each viewport pixel center
 	@param: viewport_upper_left: viewport upper left corner coordinates
*/

t_point	pixel00_loc(t_vector (*pixel_delta)[2], t_point viewport_upper_left)
{
	t_point		pixel00_loc;
	t_vector	tmp;

	tmp = add_vector((*pixel_delta)[U], (*pixel_delta[V]));
	pixel00_loc = tmp.dir;
	pixel00_loc = multiply_point(pixel00_loc, 0.5f);
	pixel00_loc = add_point(viewport_upper_left, pixel00_loc);
	return (pixel00_loc);
}
