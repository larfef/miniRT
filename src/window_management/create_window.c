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
#include "../../inc/operation.h"
#include <stdio.h>

//change to make
//calculate the radius only once
//change color field name inside color enum by hexa
//add check for mlx allocation fails

#ifndef GRADIENT_END
#define GRADIENT_END (float)-0.5
#endif

typedef	struct s_ray_tracing
{
	color		color;
	t_vector	camera_to_viewport;
	t_vector	hit_point_to_light;
	t_point		pixel_center;
	t_vector	normal;
	float		solution;
}	t_ray_tracing;

void	set_pixel_center(t_window *window, t_point *pixel_center, int x, int y)
{
	*pixel_center = add_point(multiply_point(window->pixel_delta[U].dir, x),
					multiply_point(window->pixel_delta[V].dir, y));
	*pixel_center = add_point(*pixel_center, window->pixel00_loc);
}

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_point(raytracer->camera_to_viewport.origin,
					multiply_point(raytracer->camera_to_viewport.dir,
					raytracer->solution));
}

void	set_hit_point_to_light_dir(t_ray_tracing *raytracer, t_point light_point)
{
	raytracer->hit_point_to_light.dir = sub_point(light_point, raytracer->hit_point_to_light.origin);
}

void	set_sphere_normal_vector(t_ray_tracing *raytracer, t_point a, t_point b)
{
	raytracer->normal.dir = sub_point(a, b);
}

void	set_pixel_color(t_ray_tracing *raytracer, float brightness, color color)
{
	float cos;

	cos = get_cos(raytracer->hit_point_to_light, raytracer->normal);
	raytracer->color.t_rgba.alpha = 0;
	if (cos >= 1.0 - brightness)
	{
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
		raytracer->color.color = 0x00000000;
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
	while (++y != window->height)
	{
		while (++x != window->width)
		{
			set_pixel_center(window, &raytracer.pixel_center, x, y);
			raytracer.camera_to_viewport.dir = sub_point(raytracer.pixel_center, scene->camera.coordinates);
			raytracer.solution = sphere_intersection(&shape->center,
							shape->size[0] / 2, &raytracer.camera_to_viewport);
			if (raytracer.solution > 0.0)
			{
				set_intersection_point(&raytracer);
				set_hit_point_to_light_dir(&raytracer, scene->light.coordinates);
				set_sphere_normal_vector(&raytracer, raytracer.hit_point_to_light.origin, shape->center);
				set_pixel_color(&raytracer, scene->light.brightness, shape->color);
				mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
			}
			// else
			// 	raytracer.color = ray_color(&raytracer.pixel_center);
			// mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
		}
		x = -1;
	}
}

void	set_window_height(float width, float aspect_ratio, int *height)
{
	*height = (int)roundf(width / aspect_ratio);
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
	window->mlx = mlx_init();
	window->window = mlx_new_window(window->mlx, window->width, window->height, "miniRT");
//	window->image = mlx_new_image(window->window, window->width, window->height);
	iterate_through_shapes_list(window, scene);
//	mlx_put_image_to_window(window->mlx, window->window, window->image, 0, 0);
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