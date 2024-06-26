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
	t_ray		ray;
//	t_vector	N;
	float 		t;
//	float		cos;
	int	x;
	int	y;
	t_vector	pixel_center;

	x = -1;
	y = -1;
	ray.origin = scene->camera.coordinates;
	while (++y != window->mlx.height)
	{
		while (++x != window->mlx.width)
		{
			color = scene->shapes->color;

			pixel_center = add_vector(multiply_vector(window->pixel_delta[U], x), multiply_vector(window->pixel_delta[V], y));
			pixel_center = add_vector(pixel_center, window->pixel00_loc);
			ray.dir = sub_vector(pixel_center, scene->camera.coordinates);
//			ray.dir = pixel_center;
			t = sphere_intersection(&scene->shapes->center, scene->shapes->size[0] / 2, &ray);
			if (t > 0.0) {
//				N = sub_vector(pixel_center, scene->shapes->center);
//				cos = get_theta(&scene->light.coordinates, &N);
//				if (cos >= 0)
//				{
//					color.t_rgba.red *= cos;
//					color.t_rgba.green *= cos;
//					color.t_rgba.blue *= cos;
//					color.t_rgba.alpha = 0xFF;
//				}
//				else
//					color.color = 0x000000FF;
				color.color = 0xFFFFFFFF;
			}
			else
				color = ray_color(&ray.dir);
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
