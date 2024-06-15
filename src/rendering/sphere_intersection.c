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

bool	sphere_intersection(t_vector *center, float radius, t_vector *direction)
{
	float a;
	float b;
	float c;
	float discriminant;

	a = dot_product(direction, direction);
	b = -2.0 * dot_product(direction, center);
	c = dot_product(center, center) - (radius * radius);
	discriminant = (b * b) - (4 * a * c);

	return (discriminant >= 0);
	// if (discriminant < 0)
	// 	return (-1.0);
	// return (((-1 * b) - sqrt(discriminant)) / (2.0 * a);
}
