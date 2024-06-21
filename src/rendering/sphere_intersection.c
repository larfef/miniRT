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

#include "../../inc/rendering.h"
#include <math.h>

float	sphere_intersection(t_vector *center, float radius, t_ray *ray)
{
	float a;
	float h;
	float c;
	float discriminant;
	t_vector	oc;

	oc = sub_vector(*center, ray->origin);
	a = length(&ray->dir) * length(&ray->dir);
	h = dot_product(&ray->dir, &oc);
	c = (length(&oc) * length(&oc)) - (radius * radius);

	discriminant = (h*h) - (a*c);
	if (discriminant < 0)
		return ((float)-1.0);
	return ((h - sqrt(discriminant)) / a);
}

//float	sphere_intersection(t_vector *center, float radius, t_vector *direction)
//{
//	float a;
//	float h;
//	float c;
//	float discriminant;
//
//	a = length(direction) * length(direction);
//	h = dot_product(direction, center);
//	c = (length(center) * length(center)) - (radius * radius);
//
//	discriminant = (h*h) - (a*c);
//	if (discriminant < 0) {
//		return ((float)-1.0);
//	}
//	return ((h - sqrt(discriminant)) / a);
//}

//	a = dot_product(direction, direction);
//	b = -2.0 * dot_product(direction, center);
//	discriminant = (b * b) - (4 * a * c);
