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
# include <stdint.h>
# include "types.h"
float		cylinder_intersection(t_shapes *cylinder, t_vector *hit_point);
void		get_nearest_intersection(intersection_t *fct_ptr_array, t_shapes *shape, t_ray_tracing *raytracer);
void		iterate_through_shapes_list(t_scene *scene, t_ray_tracing *raytracer);
void		iterate_through_viewport(t_window *window, t_scene *scene, t_ray_tracing *raytracer);
float       plane_intersection(t_shapes *plane, t_vector *hit_point);
void		set_pixel_color(t_ray_tracing *raytracer, float brightness, color color);
float 		sphere_intersection(t_shapes *sphere, t_vector *hit_point);
void		trace_rays(t_scene *scene, t_ray_tracing *raytracer);
#endif

