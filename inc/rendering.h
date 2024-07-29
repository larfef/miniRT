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
void		iterate_through_shapes_list(t_window *window, t_scene *scene, t_ray_tracing *raytracer);
void		iterate_through_viewport(t_window *window, t_scene *scene, t_ray_tracing *raytracer);
color		ray_color(t_vector *direction);
color		set_color(float r, float g, float b);
float 		sphere_intersection(t_shapes *sphere, t_vector *hit_point);
#endif