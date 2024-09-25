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
#include <math.h>

static void	get_discriminant(t_vector *ray, t_vector oc, float radius, t_quadratic *params)
{
	params->a = dot_product(*ray, *ray);
	params->h = dot_product(*ray, oc);
	params->c  = dot_product(oc, oc) - (radius * radius);
	params->discriminant = (params->h * params->h) - (params->a * params->c);
}

static float	get_quadratic_solution(t_quadratic *params)
{
	params->t1 = (float)(-(params->h) - sqrt(params->discriminant)) / params->a;
	params->t2 = (float)(-(params->h) + sqrt(params->discriminant)) / params->a;
	if (params->t1 > 0 && params->t2 > 0)
		return ((float)fmin((float)params->t1, (float)params->t2));
	if (params->t1 > 0)
		return params->t1;
	if (params->t2 > 0)
		return params->t2;
	return -1.0f;
}

float sphere_intersection(t_shapes *sphere, t_vector *hit_point) {
	t_vector oc = {0};
	float 	radius;
	t_quadratic	params;

	radius = sphere->size[DIAMETER] / 2;
	oc.dir = sub_point(hit_point->origin, sphere->center);
	get_discriminant(hit_point, oc, radius, &params);
	if (params.discriminant > 0)
		return (get_quadratic_solution(&params));
	return (-1.0f);
}
