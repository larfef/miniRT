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
#include "../../inc/rendering.h"
#include "math.h"

void	display(t_scene *scene, t_window *window)
{
	set_image_width(IMAGE_WIDTH, &window->mlx.width);
	set_aspect_ratio((float)WIDTH_RATIO, (float)HEIGHT_RATIO,
					 &window->aspect_ratio);
	set_window_height(window->mlx.width, window->aspect_ratio, &window->mlx.height);
	set_viewport(window->mlx.width, window->mlx.height, &window->viewport, scene->camera.fov);
	set_viewport_vectors(&window->viewport, &window->viewport_vectors, &scene->camera.orientation);
	set_pixel_delta(window->mlx.width, window->mlx.height, &window->viewport_vectors, &window->pixel_delta);
	window->viewport_upper_left = upper_left_pixel(scene->camera.coordinates, &window->viewport_vectors, scene->camera.orientation);
	window->pixel00_loc = pixel00_loc(&window->pixel_delta, window->viewport_upper_left);
	create_window(window, scene);
	if (window->mlx.window == NULL)
		___exit(NULL, scene->shapes);
}
