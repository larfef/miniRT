/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_light_coordinates.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:05:16 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/04 21:05:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/constant.h"
#include <stdbool.h>
#include <math.h>

static bool	is_point_inside_a_sphere(const t_point light_pos,
	t_shapes *sphere)
{
	float	res;

	res = ((light_pos.x - sphere->center.x)
			* (light_pos.x - sphere->center.x))
		+ ((light_pos.y - sphere->center.y)
			* (light_pos.y - sphere->center.y))
		+ ((light_pos.z - sphere->center.z)
			* (light_pos.z - sphere->center.z));
	if (sqrtf(res) < sphere->size[DIAMETER] / 2)
		return (true);
	return (false);
}

void	check_light_coordinates(t_scene *scene)
{
	t_shapes	*shape;

	shape = scene->shapes;
	while (shape)
	{
		if (shape->type == _SPHERE
			&& is_point_inside_a_sphere(scene->light.coordinates,
				shape))
			scene->light_hidden = true;
		shape = shape->next;
	}
}
