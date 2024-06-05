/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:19:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:05:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"

void	create_window(t_window *window)
{
	window->mlx.height = (int32_t)window->mlx.width / window->aspect_ratio;
	if (window->mlx.height < 1)
		window->mlx.height = 1;
	window->mlx.window = mlx_init(window->mlx.width,
								   window->mlx.height, "miniRT", false);
}
