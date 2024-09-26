/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_intersection.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:03:52 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:24 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/operation.h"

/*
	@dev:	Calculates the nearest intersection between a ray and a shape in the
			scene using a function pointer array that corresponds to the shape
			type. It updates the ray tracing structure with the closest
			intersection distance and the shape that was intersected.
	@param:	fct_ptr_array: an array of function pointers for intersection
			calculations, allowing for different intersection logic based on
			the shape type.
	@param:	shape: pointer to the shape object that is being tested for
			intersection with the ray. The function assumes the shape's type
			can be determined from this pointer.
	@param:	rt: pointer to the ray tracing structure, which stores the current
			state of the ray including the nearest intersection distance
			(`solution`) and the referenced shape.
*/

void	get_nearest_intersection(intersection_t *fct_ptr_array,
									t_shapes *shape, t_ray_tracing *rt)
{
	float	solution;

	if (shape->type == _CYLINDER)
		shape->camera_to_center.dir = sub_point(
				rt->camera_to_viewport.origin, shape->center);
	solution = fct_ptr_array[shape->type](shape, &rt->camera_to_viewport);
	if (solution == -1.0f)
		return ;
	if (!rt->solution
		|| solution < rt->solution)
	{
		rt->solution = solution;
		rt->shape = shape;
	}
}
