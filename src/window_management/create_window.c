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
#include <math.h>
#include <rendering.h>

static	void	test_draw(t_window *window, t_scene *scene)
{
	color		color;
	t_vector	center;
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y != window->mlx.height)
	{
		while (++x != window->mlx.width)
		{
			center = add_vector(multiply_vector(window->pixel_delta[U], x), multiply_vector(window->pixel_delta[V], y));
			center = add_vector(center, window->pixel00_loc);
			if (sphere_intersection(&scene->shapes->center, scene->shapes->size[0] / 2, &center)) {
				color = scene->shapes->color;
				color.t_rgba.alpha = 255;
			}
			else
				color = ray_color(&center);
			mlx_put_pixel(window->image, x, y, color.color);
		}
		x = -1;
	}
}

void	set_window_height(float width, float aspect_ratio, int32_t *height)
{
	*height = (int32_t)roundf(width / aspect_ratio);
	if (*height < 1)
		*height = 1;
}

void	create_window(t_window *window, t_scene *scene)
{
	window->mlx.window = mlx_init(window->mlx.width,
								   window->mlx.height, "miniRT", false);
	window->image = mlx_new_image(window->mlx.window, window->mlx.width, window->mlx.height);
	test_draw(window, scene);
	mlx_image_to_window(window->mlx.window, window->image, 0, 0);
}
