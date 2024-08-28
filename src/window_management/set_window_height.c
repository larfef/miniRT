#include <math.h>

void	set_window_height(float width, float aspect_ratio, int *height)
{
	*height = (int)roundf(width / aspect_ratio);
	if (*height < 1)
		*height = 1;
}
