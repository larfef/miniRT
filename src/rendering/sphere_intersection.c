/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"
#include "../../inc/constant.h"

float sphere_intersection(t_shapes *sphere, t_vector *hit_point) {
	t_vector oc = {0};
	float 	radius;
	t_quadratic	params;

	radius = sphere->size[DIAMETER] / 2;
	oc.dir = sub_point(hit_point->origin, sphere->center);
	normalize(hit_point);
	get_discriminant(hit_point, oc, radius, &params);
	if (params.discriminant > 0)
		return (get_quadratic_solution(&params));
	return (-1.0f);
}
