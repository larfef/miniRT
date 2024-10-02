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

#include "../libft/inc/libft.h"
#include "../../inc/operation.h"
#include "../../inc/constant.h"
#include <math.h>

/*
	@dev: Calculates the discriminant of the quadratic equation
		  used to determine the intersection of a ray with a sphere.

	@params: ray: A pointer to the ray vector.
			  oc: The vector from the center of the sphere
				  to the origin of the ray.
			  radius: The radius of the sphere.
			  params: A pointer to a structure holding the
					  coefficients of the quadratic equation.

	@return: None.

	@behavior:
		1. Calculate the coefficients `a`, `h`, and `c` of the
		   quadratic equation.
		2. Compute the discriminant to determine if there are
		   intersection points.
*/

static void	get_discriminant(t_vector *ray, const t_vector co,
	const float radius, t_quadratic *params)
{
	params->a = dot_product(*ray, *ray);
	params->h = dot_product(*ray, co);
	params->c = dot_product(co, co) - (radius * radius);
	params->discriminant = (params->h * params->h) - (params->a * params->c);
}

/*
	@dev: Solves the quadratic equation to find the intersection
		  points of the ray with the sphere.

	@params: params: A pointer to a structure holding the
					  coefficients of the quadratic equation.

	@return: The smallest positive intersection value (t) or
				-1.0f if there is no intersection.

	@behavior:
		1. Calculate the two potential solutions (`t1` and `t2`)
		   using the quadratic formula.
		2. Check which solution is positive.
		3. Return the smallest positive solution or -1.0f if
		   no valid solutions exist.
*/

static float	get_quadratic_solution(t_quadratic *params)
{
	params->t1 = (float)(-(params->h)
			- sqrt((double)params->discriminant)) / params->a;
	params->t2 = (float)(-(params->h)
			+ sqrt((double)params->discriminant)) / params->a;
	if (params->t1 > 0 && params->t2 > 0)
		return ((float)fmin((double)params->t1, (double)params->t2));
	if (params->t1 > 0)
		return (params->t1);
	if (params->t2 > 0)
		return (params->t2);
	return (-1.0f);
}

/*
	@dev: Computes the intersection of a ray with a sphere.

	@params: sphere: A pointer to the sphere shape object.
			  hit_point: A pointer to the ray vector used to
						  calculate intersection.

	@return: The distance to the intersection point or -1.0f if
				no intersection occurs.

	@behavior:
		1. Calculate the vector `co` from the sphere center
		   to the ray's origin.
		2. Call `get_discriminant` to compute the discriminant
		   of the intersection equation.
		3. If the discriminant is positive, call
		   `get_quadratic_solution` to get the intersection point.
		4. Return -1.0f if there is no intersection.
*/

float	sphere_intersection(t_shapes *sphere, t_vector *hit_point)
{
	t_vector	co;
	float		radius;
	t_quadratic	params;

	ft_memset(&co, 0, sizeof(co));
	radius = sphere->size[DIAMETER] / 2;
	co.dir = sub_point(hit_point->origin, sphere->center);
	get_discriminant(hit_point, co, radius, &params);
	if (params.discriminant > 0)
		return (get_quadratic_solution(&params));
	return (-1.0f);
}
