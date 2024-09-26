/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_through_viewport.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:13:52 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/26 15:13:25 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/rendering.h"
#include "../../inc/window_management.h"
#include "../../inc/operation.h"
#include "../mlx/mlx.h"
#include "../libft/inc/libft.h"
#include <stdio.h>

/*
	@dev:	Main loop that iterates through each pixel in the viewport,
			calculating the ray direction for each pixel, tracing rays
			through the scene, and determining the final color based on
			intersections with shapes and lighting conditions (e.g., light
			position and intensity).
	@param:	win: pointer to the window structure, containing information
			about the window's dimensions, current pixel coordinates,
			and the MLX context.
	@param:	scene: pointer to the scene structure, containing all scene
			data, including the camera, shapes, and lighting info
			needed for ray tracing.
	@param:	rt: pointer to the ray tracing structure, which stores the
			ray direction, pixel color, and other ray tracing-specific
			data.
	@param:	camera_to_viewport: vector representing the direction from
			the camera's origin to the center of the current pixel,
			used for ray direction.
	@param:	pixel_center: coordinates of the center of the currently
			rendered pixel, used to calculate the ray direction from
			the camera.
*/

void	iterate_through_viewport(t_window *win, t_scene *scene,
									t_ray_tracing *rt)
{
	rt->camera_to_viewport.origin = scene->camera.coordinates;
	while (++win->y != win->height)
	{
		while (++win->x != win->width)
		{
			set_pixel_center(win, &rt->pixel_center);
			rt->camera_to_viewport.dir = sub_point(rt->pixel_center,
					scene->camera.coordinates);
			iterate_through_shapes_list(scene, rt);
			trace_rays(scene, rt);
			mlx_pixel_put(win->mlx, win->window,
				win->x, win->y, rt->color.color);
		}
		progress_bar(win->y, win->height);
		win->x = -1;
	}
}
