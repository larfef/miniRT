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