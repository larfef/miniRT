/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:29:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"

/*
	@dev:	Calculates a point along a ray at a given distance. The function
			multiplies the ray vector by a scalar `t`, which represents the
			distance from the ray's origin. It then adds this scaled vector to
			the ray's original position to determine the resulting point in
			3D space.

	@param: ray: A pointer to the t_vector representing the ray. This vector
				  should contain both the origin and the direction of the ray.
	@param: t: A float representing the distance from the ray's origin at
			   which to calculate the point.

	@return: A t_vector representing the position along the ray at the
			 distance `t` from the ray's origin.
*/

t_vector	at(t_vector *ray, const float t)
{
	t_vector	result;

	result = multiply_vector(*ray, t);
	result = add_vector(*ray, result);
	return (result);
}
