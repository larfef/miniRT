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
# include "window_management_types.h"
# include "init_stack_types.h"
t_vector	at(t_vector *ray, float t);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	sub_vector(t_vector a, t_vector b);
float		dot_product(t_vector *a, t_vector *b);
t_vector	cross_product(t_vector *a, t_vector *b);
float	get_cos(t_vector *a, t_vector *b);
float	get_sin(t_vector *a, t_vector *b);
uint8_t	get_alpha(float	f);
t_vector	multiply_vector(t_vector a, float n);
float		length(t_vector *a);
void	normalize(t_vector *a);
color		ray_color(t_vector *direction);
color		set_color(float r, float g, float b);
//float		sphere_intersection(t_vector *center, float radius, t_vector *direction);
float	sphere_intersection(t_vector *center, float radius, t_vector *ray);
#endif