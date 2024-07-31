#include "../../inc/operation.h"

void	set_upper_left_pixel(t_point camera_center, t_vector (*viewport_vectors)[2], t_vector w, t_point *pos)
{
	t_vector upper_left_pixel = {0};

	t_vector half_viewport_u = multiply_vector((*viewport_vectors)[0], 0.5f);
	t_vector half_viewport_v = multiply_vector((*viewport_vectors)[1], 0.5f);
	upper_left_pixel.dir = add_point(camera_center, w.dir);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_u);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_v);
	*pos = upper_left_pixel.dir;
}
