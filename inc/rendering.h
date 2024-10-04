/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include "types.h"

void	check_light_coordinates(t_scene *scene);
float	cylinder_intersection(t_shapes *cylinder, t_vector *hit_point);
void	get_nearest_intersection(t_intersection *fct_ptr_array,
			t_shapes *shape, t_ray_tracing *raytracer);
void	iterate_through_shapes_list(t_scene *scene, t_ray_tracing *raytracer);
void	iterate_through_viewport(t_window *win, t_scene *scene,
			t_ray_tracing *rt);
void	jittered_grid(t_scene *scene, t_ray_tracing *raytracer,
			t_jittering_grid *grid);
float	plane_intersection(t_shapes *plane, t_vector *hit_point);
void	progress_bar(int y, int height);
void	set_cylinder_normal_vector(t_ray_tracing *rt);
void	set_pixel_color(t_ray_tracing *raytracer,
			float brightness, t_color color);
void	set_plane_normal_vector(t_ray_tracing *rt);
void	set_sphere_normal_vector(t_ray_tracing *raytracer);
float	sphere_intersection(t_shapes *sphere, t_vector *hit_point);
void	trace_rays(t_scene *scene, t_ray_tracing *raytracer);
#endif
