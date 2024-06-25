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
	t_ray		center;
	t_vector	N;
	float 		t;
	float		cos;
	int	x;
	int	y;

	x = -1;
	y = -1;
	center.origin = scene->camera.coordinates;

	while (++y != window->mlx.height)
	{
		while (++x != window->mlx.width)
		{
			color = scene->shapes->color;
			center.dir = add_vector(multiply_vector(window->pixel_delta[U], x), multiply_vector(window->pixel_delta[V], y));
			center.dir = add_vector(center.dir, window->pixel00_loc);
			t = sphere_intersection(&scene->shapes->center, scene->shapes->size[0] / 2, &center.dir);
			if (t > 0.0) {
				N = multiply_vector(center.dir, 2);
				cos = get_theta(&scene->light.coordinates, &N);
				if (cos >= 0) {
					// color.t_rgba.red = ((color.t_rgba.red - (color.t_rgba.red / 2)) * cos + color.t_rgba.red /2);
					// color.t_rgba.green = ((color.t_rgba.green - (color.t_rgba.green / 2)) * cos + color.t_rgba.green /2);
					// color.t_rgba.blue = ((color.t_rgba.blue - (color.t_rgba.blue / 2)) * cos + color.t_rgba.blue /2);
					color.t_rgba.red = cos * color.t_rgba.red;
					color.t_rgba.green = cos * color.t_rgba.green;
					color.t_rgba.blue = cos * color.t_rgba.blue;
				}
				else
				{
					// color.color = 0xFFFFFFFF;
					// color.t_rgba.red = color.t_rgba.red / 2 + cos * (color.t_rgba.red / 2);
					// color.t_rgba.green = (color.t_rgba.green / 2) + cos * (color.t_rgba.green / 2);
					// color.t_rgba.blue = (color.t_rgba.blue / 2) + cos * (color.t_rgba.blue / 2);
					color.color = 0x00000000;
				}
				color.t_rgba.alpha = 0xFF;
				// N = at(&center, t);
				// N = sub_vector(N, scene->shapes->center);
				// N = unit_vector(&N);
				// color = set_color((N.x + 1.0) * 0.5, (N.y + 1.0) * 0.5, (N.z + 1.0) * 0.5);
			}
			else
				color = ray_color(&center.dir);
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
