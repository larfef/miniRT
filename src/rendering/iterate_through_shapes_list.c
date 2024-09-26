/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_through_shapes_list.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:03:52 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/26 14:53:05 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/rendering.h"

/*
	@dev:	Iterates through the list of shapes in the scene, checking for
			intersections between each shape and the ray from the camera.
			Updates the ray tracer with the nearest intersection point if
			found, so the ray can be traced correctly.
	@param:	scene: pointer to the scene structure, which contains the list
			of shapes. Each shape in this list is tested for intersections
			with the ray.
	@param:	raytracer: pointer to the ray tracing structure, which contains
			the current ray's data, including its direction and the nearest
			intersection solution. This structure will be updated with the
			closest intersection found.
*/

void	iterate_through_shapes_list(t_scene *scene,
										t_ray_tracing *raytracer)
{
	t_shapes	*shape;

	shape = scene->shapes;
	raytracer->solution = 0.0f;
	while (shape)
	{
		get_nearest_intersection(scene->intersection, shape, raytracer);
		shape = shape->next;
	}
}
