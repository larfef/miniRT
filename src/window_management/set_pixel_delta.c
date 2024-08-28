#include "../../inc/window_management.h"
#include "../../inc/operation.h"

void	set_pixel_delta(int32_t image_width, int32_t image_height, t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2])
{
	(*pixel_delta)[U] = multiply_vector((*viewport_vectors)[U], (1 / (float)image_width));
	(*pixel_delta)[V] = multiply_vector((*viewport_vectors)[V], (1 / (float)image_height));
}
