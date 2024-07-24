/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/hooks.h"
#include "../mlx/mlx.h"

void	init_hooks(t_hook *param, t_window *window, t_scene *scene)
{
	param->mlx = window->mlx;
	param->window = window->window;
	param->shapes = scene->shapes;
	mlx_hook(window->window, 2, 0, &k_input, param);
	mlx_hook(window->window, 17, 0, &close_window, param);
}
