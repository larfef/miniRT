#include "../../inc/window_management.h"
#include <stdlib.h>

int	k_input(int key, t_window *window)
{
	if (key == 53)
	{
		mlx_clear_window(window->mlx, window->window);
		exit(0);
	}
	return (0);
}
