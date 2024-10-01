/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:39:10 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../inc/types.h"
#include "../inc/operation.h"

/*
	@dev:	Calculates the normal vector at a point on the cylinder surface.
			Assumes the cylinder is aligned with its direction vector
			and centered at the origin. The normal points outward from
			the surface.

	@param: cylinder: Pointer to a t_shapes structure for the cylinder.
	@param: point: A t_vector representing a point on the cylinder surface
				   where the normal is calculated.

	@return: A t_vector representing the outward normal at the point,
			 normalized to unit length.
*/

t_vector	cylinder_normal(t_shapes *cylinder, const t_vector point)
{
	t_vector	cylinder_center;
	t_vector	center_to_point;
	t_vector	q;
	t_vector	normal;
	float		t;

	ft_memset(&cylinder_center, 0, sizeof(cylinder_center));
	cylinder_center.dir = cylinder->center;
	center_to_point = sub_vector(point, cylinder_center);
	t = dot_product(center_to_point, cylinder->orientation)
		/ dot_product(cylinder->orientation, cylinder->orientation);
	q = add_vector(cylinder_center,
			multiply_vector(cylinder->orientation, t));
	normal = sub_vector(point, q);
	normalize(&normal);
	return (normal);
}
