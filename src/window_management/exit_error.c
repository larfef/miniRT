/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 20:55:45 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx/mlx.h"
#include "../../inc/init_stack.h"

/*
	@dev: Cleans up resources and exits the program when an error
		  occurs during window creation or rendering.

	@params: ptr:  A pointer to the `t_window` struct, which holds
				   information about the `mlx` instance and the window.
			  list: A pointer to the `t_shapes` list, which contains
					the shapes in the scene that need to be freed.

	@return: None.

	@behavior:
		1. Clears the window using the `mlx_clear_window` function,
		   freeing the display resources associated with it.
		2. Calls `free_list` to free all memory allocated for the
		   shapes list in the scene.
		3. Exits the program with an exit status of `1` to indicate
		   an error occurred.
*/

void	exit_error(t_window *ptr, t_shapes *list)
{
	mlx_clear_window(ptr->mlx, ptr->window);
	free_list(list);
	exit(1);
}
