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

#include "init_stack.h"
#include "window_management.h"
#include "operation.h"

//void	render_scene(t_scene *scene, t_window *win, t_ray_tracing *raytracer)
//{
//	iterate_through_viewport(win, scene, raytracer);
//}

//void	render_scene(t_scene *scene, t_window *win, t_ray_tracing *raytracer)
//{
//	set_image_width(IMAGE_WIDTH, &win->width);
//	set_aspect_ratio((float)WIDTH_RATIO, (float)HEIGHT_RATIO,
//					 &win->aspect_ratio);
//	set_window_height((float)win->width, win->aspect_ratio, &win->height);
//	set_viewport(win->width, win->height, &win->viewport, scene->camera.fov);
//	set_viewport_vectors(&win->viewport, &win->viewport_vectors,
//						 &scene->camera.orientation);
//	set_pixel_delta(win->width, win->height, &win->viewport_vectors,
//					&win->pixel_delta);
//	set_upper_left_pixel(scene->camera.coordinates,
//						 &win->viewport_vectors, scene->camera.orientation,
//						 &win->viewport_upper_left);
//	set_pixel00_loc(&win->pixel_delta, win->viewport_upper_left,
//					&win->pixel00_loc);
//	create_window(win, scene);
//	iterate_through_viewport(win, scene, raytracer);
//}
