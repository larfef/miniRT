#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../../inc/init_stack.h"

void	exit_error(t_window *ptr, t_shapes *list)
{
	mlx_clear_window(ptr->mlx, ptr->window);
	free_list(list);
	exit(1);
}
