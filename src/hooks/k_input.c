#include "../../inc/types.h"
#include "../../inc/init_stack.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	k_input(int key, t_hook *ptr)
{
	if (key == 53)
	{
		mlx_clear_window(ptr->mlx, ptr->window);
		free_list(ptr->shapes);
		exit(0);
	}
	return (0);
}
