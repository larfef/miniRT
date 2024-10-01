#include <stdio.h>

#include "../../inc/types.h"
#include "../inc/key_codes.h"
#include "../../inc/init_stack.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	k_input(int key, t_hook *ptr)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(ptr->mlx, ptr->window);
		free_list(ptr->shapes);
		exit(0);
	}
	return (0);
}
