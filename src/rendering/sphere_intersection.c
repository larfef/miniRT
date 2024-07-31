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

//float sphere_intersection(t_point *center, float radius, t_vector *ray) {
//    t_vector oc = {{0,0,0},{0,0,0}};
//
//	oc.dir = sub_point(ray->origin, *center);
//
//    // Ensure the ray direction is normalized
//    normalize(ray);
//
//    float a = dot_product(*ray, *ray);
//    float h = dot_product(*ray, oc);
//    float c = dot_product(oc, oc) - (radius * radius);
//
//    float discriminant = (h * h) - (a * c);
//    if (discriminant < 0) {
//        return -1.0f;
//    }
//
//    // Calculate the two potential intersection points
//    float t1 = (-h - sqrt(discriminant)) / a;
//    float t2 = (-h + sqrt(discriminant)) / a;
//
//    // Return the nearest positive intersection point
//    if (t1 > 0 && t2 > 0) {
//        return fmin(t1, t2);
//    } else if (t1 > 0) {
//        return t1;
//    } else if (t2 > 0) {
//        return t2;
//    }
//
//    return -1.0f;
//}
