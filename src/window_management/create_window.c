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

//change to make
//calculate the radius only once
//loop trought shapes list
//change color field name inside color enum by hexa
//change mlx codam by mlx42
//add check for mlx allocation fails

#ifndef GRADIENT_END
#define GRADIENT_END (float)-0.0
#endif

typedef	struct s_ray_tracing
{
	color		color;
	t_ray		camera_to_viewport;
	t_ray		hit_point_to_light;
	t_vector	pixel_center;
	t_vector	normal;
	float		cos;
	float		solution;
}t_ray_tracing;

void	set_pixel_center(t_window *window, t_vector *pixel_center, int x, int y)
{
	*pixel_center = add_vector(multiply_vector(window->pixel_delta[U], x),
					multiply_vector(window->pixel_delta[V], y));
	*pixel_center = add_vector(*pixel_center, window->pixel00_loc);
}

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_vector(raytracer->camera_to_viewport.origin,
					multiply_vector(raytracer->camera_to_viewport.dir,
					raytracer->solution));
}

void	set_hit_point_to_light_dir(t_ray_tracing *raytracer, t_vector light_point)
{
	raytracer->hit_point_to_light.dir = sub_vector(light_point, raytracer->hit_point_to_light.origin);
}

void	set_sphere_normal_vector(t_ray_tracing *raytracer, t_vector a, t_vector b)
{
	raytracer->normal = sub_vector(a, b);
}

void	set_pixel_color(t_ray_tracing *raytracer, float brightness, color color)
{
	float cos;

	cos = get_cos(&raytracer->hit_point_to_light.dir, &raytracer->normal);
	raytracer->color.t_rgba.alpha = 255;
	if (cos >= 1.0 - brightness) {
		// Full color
		raytracer->color.t_rgba.red = color.t_rgba.red;
		raytracer->color.t_rgba.green = color.t_rgba.green;
		raytracer->color.t_rgba.blue = color.t_rgba.blue;
	}
	else if (cos < 1.0 - brightness && cos >= GRADIENT_END) {
		// Calculate the brightness factor for the gradient from color to black
		float brightness_factor = (cos + (-1.0 * GRADIENT_END)) / (1.0 - brightness + (-1.0 * GRADIENT_END));

		// Apply the gradient
		raytracer->color.t_rgba.red = color.t_rgba.red * brightness_factor;
		raytracer->color.t_rgba.green = color.t_rgba.green * brightness_factor;
		raytracer->color.t_rgba.blue = color.t_rgba.blue * brightness_factor;
	}
	else if (cos < GRADIENT_END) {
		// Fully black
		raytracer->color.color = 0x000000FF;
	}
}

void	trace_rays(t_window *window, t_scene *scene, t_shapes *shape)
{
	int32_t		x;
	int32_t		y;
	t_ray_tracing	raytracer;

	x = -1;
	y = -1;
	raytracer.camera_to_viewport.origin = scene->camera.coordinates;
	while (++y != window->mlx.height)
	{
		while (++x != window->mlx.width)
		{
			set_pixel_center(window, &raytracer.pixel_center, x, y);
			raytracer.camera_to_viewport.dir = sub_vector(raytracer.pixel_center, scene->camera.coordinates);
			raytracer.solution = sphere_intersection(&shape->center,
							shape->size[0] / 2, &raytracer.camera_to_viewport);
			if (raytracer.solution > 0.0)
			{
				set_intersection_point(&raytracer);
				set_hit_point_to_light_dir(&raytracer, scene->light.coordinates);
				set_sphere_normal_vector(&raytracer, raytracer.hit_point_to_light.origin, shape->center);
				set_pixel_color(&raytracer, scene->light.brightness, shape->color);
				mlx_put_pixel(window->image, x, y, raytracer.color.color);
			}
			// else
			// 	raytracer.color = ray_color(&raytracer.pixel_center);
			// mlx_put_pixel(window->image, x, y, raytracer.color.color);
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

void	iterate_through_shapes_list(t_window *window, t_scene *scene)
{
	t_shapes *shape;

	shape = scene->shapes;
	while (shape)
	{
		trace_rays(window, scene, shape);
		shape = shape->next;
	}
}

void	create_window(t_window *window, t_scene *scene)
{
	window->mlx.window = mlx_init(window->mlx.width,
								   window->mlx.height, "miniRT", false);
	window->image = mlx_new_image(window->mlx.window, window->mlx.width, window->mlx.height);
	iterate_through_shapes_list(window, scene);
	mlx_image_to_window(window->mlx.window, window->image, 0, 0);
}

// if (cos >= 1.0 - brightness)
// {
// 	raytracer->color.t_rgba.red =  color.t_rgba.red;
// 	raytracer->color.t_rgba.green = color.t_rgba.green;
// 	raytracer->color.t_rgba.blue = color.t_rgba.blue;
// }
// if (cos < 1.0 - brightness && cos > 0) {
// 	float brightness_factor = cos / (1.0 - brightness);
// 	raytracer->color.t_rgba.red = color.t_rgba.red * brightness_factor;
// 	raytracer->color.t_rgba.green = color.t_rgba.green * brightness_factor;
// 	raytracer->color.t_rgba.blue = color.t_rgba.blue * brightness_factor;
// }
// else if (cos < 0)
// 	raytracer->color.color = 0x000000FF;