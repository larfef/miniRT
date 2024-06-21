#include "../../inc/window_management.h"
#include "../../inc/rendering.h"

void	set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2])
{
	(*viewport)[V] = 1.0;
	(*viewport)[U] = (*viewport)[V] * ((float)image_width / (float)image_height);
}
