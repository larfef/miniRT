/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 20:55:33 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"
#include "../../inc/rendering.h"
#include "../../inc/operation.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <math.h>

/*
	@dev: Creates and initializes a new graphical window using the
		  `mlx` library for rendering the scene.

	@params: window: A pointer to the `t_window` struct, which holds
					 information about the window and `mlx` instance.
			  scene: A pointer to the `t_scene` struct, which contains
					 the scene data, including shapes for rendering.

	@return: None.

	@behavior:
		1. Initialize the `mlx` instance and assign it to the `window->mlx`
		   member. If initialization fails, call `exit_error` to handle
		   the failure and exit the program.
		2. Create a new window with the specified width and height, and
		   set its title to "miniRT". If window creation fails, call
		   `exit_error` to handle the failure and exit the program.
*/

void	create_window(t_window *window, t_scene *scene)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		exit_error(window, scene->shapes);
	window->window = mlx_new_window(window->mlx, window->width,
			window->height, "miniRT");
	if (!window->window)
		exit_error(window, scene->shapes);
}
