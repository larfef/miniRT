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
#include "../../inc/rendering.h"
#include "../../inc/operation.h"
#include "../mlx/mlx.h"
#include <stdio.h>
#include <math.h>

//change to make
//calculate the radius only once
//change color field name inside color enum by hexa
//add check for mlx allocation fails
//test error protection

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

t_vector cylinder_normal(t_shapes *cylinder, t_vector point) {
	// Step 1: Calculate vector from cylinder center to point
	t_vector cylinder_center = {{0,0,0}, cylinder->center};

	t_vector CP = sub_vector(point, cylinder_center);

	// Step 2: Project CP onto the cylinder's orientation vector

	float t = dot_product(CP, cylinder->orientation) / dot_product(cylinder->orientation, cylinder->orientation);

	// Step 3: Calculate the point Q on the cylinder's axis
	t_vector Q = add_vector(cylinder_center, multiply_vector(cylinder->orientation, t));

	// Step 4: Calculate the normal vector as the vector from Q to the point
	t_vector N = sub_vector(point, Q);

	// Step 5: Normalize the normal vector
	normalize(&N);

	return N;
}

void	init_raytracer_struct(t_scene *scene, t_shapes *shape, t_ray_tracing *raytracer)
{
	raytracer->camera_to_viewport.origin = scene->camera.coordinates;

}

void	trace_rays(t_window *window, t_scene *scene, t_shapes *shape, t_ray_tracing *raytracer)
{
	if (raytracer->solution > 0.0)
	{
		set_intersection_point(raytracer);
		set_hit_point_to_light_dir(raytracer, scene->light.coordinates);
		raytracer.normal = cylinder_normal(shape, (t_vector){{0, 0, 0}, raytracer.hit_point_to_light.origin});
		set_sphere_normal_vector(raytracer, raytracer.hit_point_to_light.origin, shape->center);
		set_pixel_color(raytracer, scene->light.brightness, shape->color);
		raytracer.color = shape->color;
		mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
	}
//	 else
//		raytracer.color = ray_color(&raytracer.pixel_center);
//	 mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
}

void	create_window(t_window *window, t_scene *scene)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		exit_error(window, scene->shapes);
	window->window = mlx_new_window(window->mlx, window->width, window->height, "miniRT");
	if (!window->window)
		exit_error(window, scene->shapes);
}

//void	trace_rays(t_window *window, t_scene *scene, t_shapes *shape)
//{
//	int32_t		x;
//	int32_t		y;
//	t_ray_tracing	raytracer;
//
//	x = -1;
//	y = -1;
//	init_raytracer_struct(scene, shape, &raytracer);
//	while (++y != window->height)
//	{
//		while (++x != window->width)
//		{
//			set_pixel_center(window, &raytracer.pixel_center, x, y);
//			raytracer.camera_to_viewport.dir = sub_point(raytracer.pixel_center, scene->camera.coordinates);
//			raytracer.solution = sphere_intersection(&shape->center,
//													 shape->size[0] / 2, &raytracer.camera_to_viewport);
//			raytracer.solution = cylinder_intersection(shape, &raytracer.camera_to_viewport);
//			if (raytracer.solution > 0.0)
//			{
//				set_intersection_point(&raytracer);
//				set_hit_point_to_light_dir(&raytracer, scene->light.coordinates);
//				raytracer.normal = cylinder_normal(shape, (t_vector){{0, 0, 0}, raytracer.hit_point_to_light.origin});
//				set_sphere_normal_vector(&raytracer, raytracer.hit_point_to_light.origin, shape->center);
//				set_pixel_color(&raytracer, scene->light.brightness, shape->color);
//				raytracer.color = shape->color;
//				mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
//			}
//			else
//				raytracer.color = ray_color(&raytracer.pixel_center);
//			mlx_pixel_put(window->mlx, window->window, x, y, raytracer.color.color);
//		}
//		x = -1;
//	}
//}