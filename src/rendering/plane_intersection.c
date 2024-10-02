/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:32:06 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 13:28:20 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/operation.h"
#include "../../inc/constant.h"
#include <math.h>

float	plane_linear_equation(t_vector *normal, t_point *point_on_plane,
	t_point *ray_origin, t_point *ray_direction)
{
	t_vector	ray_to_plane;
	float		numerator;
	float		denominator;
	float		t;

	ft_memset(&ray_to_plane, 0, sizeof(ray_to_plane));
	denominator = dot_product(*normal, (t_vector){{0, 0, 0},
			*ray_direction});
	if (fabs((double)denominator) < EPSILON)
		return (-1.0f);
	ray_to_plane.dir = sub_point(*point_on_plane, *ray_origin);
	numerator = dot_product(*normal, ray_to_plane);
	t = numerator / denominator;
	if (t > 0)
		return (t);
	return (-1.0f);
}

float	plane_intersection(t_shapes *plane, t_vector *ray)
{
	return (plane_linear_equation(&plane->orientation,
			&plane->center, &ray->origin, &ray->dir));
}
