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

float sphere_intersection(t_vector *center, float radius, t_ray *ray) {
    t_vector oc = sub_vector(ray->origin, *center);

    // Ensure the ray direction is normalized
    normalize(&ray->dir);

    float a = dot_product(&ray->dir, &ray->dir);
    float h = dot_product(&ray->dir, &oc);
    float c = dot_product(&oc, &oc) - (radius * radius);

    float discriminant = (h * h) - (a * c);
    if (discriminant < 0) {
        return -1.0f;
    }

    // Calculate the two potential intersection points
    float t1 = (-h - sqrt(discriminant)) / a;
    float t2 = (-h + sqrt(discriminant)) / a;

    // Return the nearest positive intersection point
    if (t1 > 0 && t2 > 0) {
        return fmin(t1, t2);
    } else if (t1 > 0) {
        return t1;
    } else if (t2 > 0) {
        return t2;
    }

    return -1.0f;
}

// float	sphere_intersection(t_vector *center, float radius, t_ray *ray)
// {
// 	float a;
// 	float h;
// 	float c;
// 	float discriminant;
// 	t_vector	oc;
//
// 	oc = sub_vector(*center, ray->origin);
// 	a = length(&ray->dir) * length(&ray->dir);
// 	h = dot_product(&ray->dir, &oc);
// 	c = (length(&oc) * length(&oc)) - (radius * radius);
// //	h *= -1;
// 	discriminant = (h * h) - (a * c);
// 	if (discriminant < 0)
// 		return ((float)-1.0);
// 	return ((h + sqrt(discriminant)) / a);
// }
