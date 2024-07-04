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
#include <stdio.h>

static	void	test_draw(t_window *window, t_scene *scene)
{
	color		color;
	t_ray		ray;
	// from sphere intersection to light
	t_ray		light;
	t_vector	N;
	float 		t;
	float		cos;
//	float 		sin;
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
			t = sphere_intersection(&scene->shapes->center, scene->shapes->size[0] / 2, &ray);
			if (t > 0.0) {
				light.origin = add_vector(ray.origin, multiply_vector(ray.dir, t));
				light.dir = sub_vector(scene->light.coordinates, light.origin);
//				light.dir = unit_vector(&light.dir);
				N = sub_vector(light.origin, scene->shapes->center);
//				N = unit_vector(&N);
				cos = get_cos(&light.dir, &N);
//				printf("Intersection at (%f, %f, %f)\n", light.origin.x, light.origin.y, light.origin.z);
//				printf("Normal at intersection (%f, %f, %f)\n", N.x, N.y, N.z);
//				printf("Light direction (%f, %f, %f)\n", light.dir.x, light.dir.y, light.dir.z);
//				printf("Cosine: %f\n", cos);
				if (cos >= 1.0 - scene->light.brightness)
					color.t_rgba.alpha = 255;
				if (cos < 1.0 - scene->light.brightness && cos > 0) {
//					float brightness_factor = cos / scene->light.brightness;
					color.t_rgba.red *= cos;
					color.t_rgba.green *= cos;
					color.t_rgba.blue *= cos;
					color.t_rgba.alpha = 255; // Fully opaque}
				}
				else if (cos < 0)
					color.color = 0x000000FF;
//				if (cos < 0)
//				{
//					sin = get_sin(&light.dir, &N);
//					color.t_rgba.red *= sin;
//					color.t_rgba.green *= sin;
//					color.t_rgba.blue *= sin;
//				}
			}
			else
				color = ray_color(&pixel_center);
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
