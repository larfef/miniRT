/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:59:35 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 12:35:26 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/types.h"
#include "../../inc/constant.h"
#include "../../inc/operation.h"
#include <math.h>

/*
	@dev:	Computes the discriminant for a ray-cylinder
			intersection using quadratic equations. The
			discriminant helps determine if and where the
			ray intersects the surface of the cylinder.

	@params: ray: The ray vector representing the direction
				 and origin of the ray from the camera or
				 light source.
	@params: oc: Vector from the ray's origin to the center
				 of the cylinder. This helps determine the
				 relative position of the ray and cylinder.
	@params: cy: A pointer to the cylinder shape containing
				 its size, orientation, and position.
	@params: solver: A pointer to the quadratic structure
					where coefficients and the discriminant
					are stored.

	@return: Modifies the solver structure, storing the
			 discriminant and quadratic coefficients.

	@behavior:
		1. Calculate the radius of the cylinder by halving
		   its diameter.
		2. Compute the coefficients `a`, `h`, and `c` for
		   the quadratic equation.
		3. Calculate the discriminant based on the
		   quadratic formula.
*/

static void	get_discriminant(t_vector *ray, t_vector oc, t_shapes *cy,
								t_quadratic *solver)
{
	float	radius;

	radius = cy->size[DIAMETER] / 2;
	solver->a = dot_product(*ray, *ray);
	solver->h = 2 * dot_product(*ray, oc);
	solver->c = dot_product(oc, oc) - (radius * radius)
		* dot_product(cy->orientation, cy->orientation);
	solver->discriminant = (solver->h * solver->h)
		- (4 * solver->a * solver->c);
}

/*
	@dev:	Solves a quadratic equation for two possible
			intersection points based on the computed
			discriminant.

	@params: params: A pointer to the quadratic structure
					 containing the coefficients and
					 discriminant of the quadratic equation.

	@return: None. Updates the structure with two potential
			 solutions (`t1` and `t2`) for the intersection
			 points.

	@behavior:
		1. Compute the square root of the discriminant.
		2. Calculate two solutions (`t1` and `t2`) based
		   on the quadratic formula.
*/

static void	get_solutions(t_quadratic *params)
{
	float	sqrt_discriminant;

	sqrt_discriminant = (float)sqrt((double)params->discriminant);
	params->t1 = (-params->h - sqrt_discriminant) / (2 * params->a);
	params->t2 = (-params->h + sqrt_discriminant) / (2 * params->a);
}

/*
	@dev:	Checks whether the intersection point lies
			within the height limits of the finite cylinder.
			This ensures the ray intersects within the
			cylindrical boundaries and not its infinite
			extension.

	@params: ray: The ray vector representing the direction
				  and origin of the ray in the scene.
	@params: t: The parameter representing the distance to
				the intersection point along the ray.
	@params: cylinder: A pointer to the cylinder object
					   which contains its center,
					   orientation, and size information.
	@params: height: The cylinder's height used to check
					 the boundaries.

	@return: Returns `true` if the intersection point is
			 within the cylinder's height bounds; otherwise
			 `false`.

	@behavior:
		1. Calculate the point of intersection based on the
		   ray's direction and the distance `t`.
		2. Compute the vector from the cylinder's center to
		   this intersection point.
		3. Measure the length of this vector along the
		   cylinder's orientation.
		4. If the length is within the cylinder's height,
		   return `true`; otherwise `false`.
*/

static bool	is_part_of_the_cylinder(t_vector *ray, const float t,
										t_shapes *cylinder, const float height)
{
	t_vector	p;
	t_vector	center_to_border;
	t_vector	center;
	float		length;

	ft_memset(&center, 0, sizeof(center));
	center.dir = cylinder->center;
	p = add_vector(*ray, multiply_vector(*ray, t));
	center_to_border = sub_vector(p, center);
	length = dot_product(center_to_border, cylinder->orientation);
	if (length >= -height / 2 && length <= height / 2)
		return (true);
	return (false);
}

/*
	@dev:	Calculates the closest intersection between a
			ray and a cylinder using the quadratic
			discriminant and solutions. Ensures the
			intersection is within the cylinder's height
			bounds.

	@params: cylinder: A pointer to the cylinder shape
					  containing attributes like size,
					  orientation, and position.
	@params: ray: A pointer to the ray vector representing
				  its direction and origin in the scene.

	@return: Returns the closest intersection point (`t`)
			 if valid; if no valid intersection is found,
			 returns -1.0f.

	@behavior:
		1. Compute cross products necessary for the
		   discriminant calculation.
		2. Call `get_discriminant` to calculate the
		   discriminant for the ray-cylinder intersection.
		3. If the discriminant is negative, return -1.0f.
		4. Solve for potential intersection points (`t1`, `t2`).
		5. Check if each point is part of the finite cylinder
		   using `is_part_of_the_cylinder`.
		6. Return the closest valid intersection point or
		   -1.0f if no valid point exists.
*/

float	cylinder_intersection(t_shapes *cylinder, t_vector *ray)
{
	t_vector	cov;
	t_vector	dv;
	t_quadratic	params;

	ft_memset(&dv, 0, sizeof(dv));
	ft_memset(&params, 0, sizeof(params));
	dv = cross_product(*ray, cylinder->orientation);
	cov = cross_product(cylinder->camera_to_center, cylinder->orientation);
	get_discriminant(&dv, cov, cylinder, &params);
	if (params.discriminant < 0)
		return (-1.0f);
	get_solutions(&params);
	if (params.t1 >= 0 && is_part_of_the_cylinder(ray, params.t1, cylinder,
			cylinder->size[HEIGHT]))
		return (params.t1);
	if (params.t2 >= 0 && is_part_of_the_cylinder(ray, params.t2, cylinder,
			cylinder->size[HEIGHT]))
		return (params.t2);
	return (-1.0f);
}
