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

#include "../../inc/init_stack.h"
#include "../../inc/window_management.h"

void	set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2])
{
	(*viewport)[HEIGHT] = 2.0;
	(*viewport)[WIDTH] = (*viewport)[HEIGHT] * ((float)image_width / (float)image_height);
}

void	display(t_scene *scene, t_window *window)
{
	set_image_width(IMAGE_WIDTH, &window->mlx.width);
	set_aspect_ratio((float)WIDTH_RATIO, (float)HEIGHT_RATIO,
					 &window->aspect_ratio);
	set_window_height(window->mlx.width, window->aspect_ratio, &window->mlx.height);
	set_viewport(window->mlx.width, window->mlx.height, &window->viewport);
	create_window(window);
	if (window->mlx.window == NULL)
		___exit(NULL, scene->shapes);
}
