#include "../../inc/window_management.h"
#include "../../inc/rendering.h"

t_vector upper_left_pixel(t_vector camera_center, t_vector (*viewport_vectors)[2], t_vector w)
{
	t_vector upper_left_pixel;

	t_vector half_viewport_u = multiply_vector((*viewport_vectors)[0], 0.5);
	t_vector half_viewport_v = multiply_vector((*viewport_vectors)[1], 0.5);
	upper_left_pixel = sub_vector(camera_center, w);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_u);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_v);
	return (upper_left_pixel);
}
