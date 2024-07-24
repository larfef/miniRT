/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/hooks.h"
#include "../../inc/init_stack.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

/*
	@dev: close the window when clicking the red cross button
	and free the shapes list
 	@param: ptr: structure with at least a pointer to the mlx instance,
 	the window instance and a list
*/

int	close_window(t_hook *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->window);
	free_list(ptr->shapes);
	exit(0);
}
