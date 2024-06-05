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

void	display(t_scene *scene, t_window *window)
{
	(void)scene;

	set_image_width(IMAGE_WIDTH, &window->mlx.width);
	set_aspect_ratio((float)WIDTH_RATIO, (float)HEIGHT_RATIO,
					 &window->aspect_ratio);
	create_window(window);
	if (!window->mlx.window)
		___exit(NULL, scene->shapes);
}
