/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H
# include "types.h"

t_point		add_point(t_point a, t_point b);
t_vector	add_vector(t_vector a, t_vector b);
t_vector	at(t_vector *ray, float t);
t_vector	cross_product(t_vector a, t_vector b);
t_vector	cylinder_normal(t_shapes *cylinder, t_vector point);
float		dot_product(t_vector a, t_vector b);
float		get_cos(t_vector a, t_vector b);
float		length(t_vector a);
t_point		multiply_point(t_point a, float n);
t_vector	multiply_vector(t_vector a, float n);
void		normalize(t_vector *a);
t_point		sub_point(t_point a, t_point b);
t_vector	sub_vector(t_vector a, t_vector b);
#endif