#include "../../inc/window_management.h"

void	set_viewport_vectors(float (*viewport)[2], t_vector (*viewport_vectors)[2])
{
	(*viewport_vectors)[U].x = (*viewport)[WIDTH];
	(*viewport_vectors)[V].y = -1 * ((*viewport)[HEIGHT]);
}
