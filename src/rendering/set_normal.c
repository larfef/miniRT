/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:45:34 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 15:45:55 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/types.h"
#include "../inc/operation.h"

/*
	@dev: Sets the normal vector for a sphere based on the
		  hit point and the sphere's center.

	@params: raytracer: The ray tracing object that holds
						intersection data.

	@return: None.

	@behavior:
		1. Subtract the hit point from the sphere's center
		   to find the normal vector.
*/

void	set_sphere_normal_vector(t_ray_tracing *raytracer)
{
	raytracer->normal.dir = sub_point(raytracer->hit_point_to_light.origin,
			raytracer->shape->center);
}

/*
	@dev: Sets the normal vector for a cylinder and checks if
		  the intersection between the ray and the cylinder occurs inside.

	@params: rt: The ray tracing object containing the shape
				 and hit point data.

	@return: None.

	@behavior:
		1. Calculate the cylinder's normal vector.
		2. Check if the ray is inside the cylinder.
		3. Flip the normal if the ray is inside.
*/

void	set_cylinder_normal_vector(t_ray_tracing *rt)
{
	rt->normal = cylinder_normal(rt->shape,
			(t_vector){{0, 0, 0}, rt->hit_point_to_light.origin});
	if (dot_product(rt->normal, rt->camera_to_viewport) > 0)
	{
		rt->is_inside = true;
		rt->normal = multiply_vector(rt->normal, -1);
	}
	else
		rt->is_inside = false;
}

/*
	@dev: Sets the normal vector for a plane based on its
		  orientation and hit point.

	@params: rt: The ray tracing object that contains the
				 shape and hit point information.

	@return: None.

	@behavior:
		1. Normalize the plane's orientation.
		2. Flip the normal if the angle with the ray is obtuse.
*/

void	set_plane_normal_vector(t_ray_tracing *rt)
{
	rt->normal = rt->shape->orientation;
	if (rt->shape->type == _PLANE
		&& get_cos(rt->hit_point_to_light, rt->normal) < 0)
		rt->normal = multiply_vector(rt->normal, -1);
}
