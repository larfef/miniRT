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

void	set_pixel_delta(int32_t image_width, int32_t image_height, t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2])
{
	(*pixel_delta)[U] = multiply_vector((*viewport_vectors)[U], (1 / (float)image_width));
	(*pixel_delta)[V] = multiply_vector((*viewport_vectors)[V], (1 / (float)image_height));
}

void	set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2])
{
	(*viewport)[V] = 2.0;
	(*viewport)[U] = (*viewport)[V] * ((float)image_width / (float)image_height);
}

void	set_viewport_vectors(float (*viewport)[2], t_vector (*viewport_vectors)[2])
{
	(*viewport_vectors)[U].x = (*viewport)[WIDTH];
	(*viewport_vectors)[V].y = -1 * ((*viewport)[HEIGHT]);
}

void upper_left_pixel(t_vector camera_center, t_vector focal_length, t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2]) {
	t_vector upper_left_pixel;

	(void)pixel_delta;
	t_vector focal_length_vec = {0, 0, focal_length.z};
	t_vector half_viewport_u = multiply_vector((*viewport_vectors)[0], 0.5);
	t_vector half_viewport_v = multiply_vector((*viewport_vectors)[1], 0.5);
	upper_left_pixel = sub_vector(camera_center, focal_length_vec);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_u);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_v);
}

void	display(t_scene *scene, t_window *window)
{
	window->focal_length.z = 1.0;
	set_image_width(IMAGE_WIDTH, &window->mlx.width);
	set_aspect_ratio((float)WIDTH_RATIO, (float)HEIGHT_RATIO,
					 &window->aspect_ratio);
	set_window_height(window->mlx.width, window->aspect_ratio, &window->mlx.height);
	set_viewport(window->mlx.width, window->mlx.height, &window->viewport);
	set_viewport_vectors(&window->viewport, &window->viewport_vectors);
	set_pixel_delta(window->mlx.width, window->mlx.height, &window->viewport_vectors, &window->pixel_delta);
	upper_left_pixel(scene->camera.coordinates, window->focal_length, &window->viewport_vectors, &window->pixel_delta);
	create_window(window);
	if (window->mlx.window == NULL)
		___exit(NULL, scene->shapes);
}
