/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jittered_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:16:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 13:18:22 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/rendering.h"
#include "../inc/types.h"
#include "../inc/operation.h"
#include "../inc/constant.h"

static bool	check_conditions(t_ray_tracing *rt, t_shapes *shape,
								t_vector *shadow_ray)
{
	if (length(*shadow_ray) > MAX_RAY_DEPTH)
		return (false);
	if (shape == rt->shape)
		return (false);
	if (rt->shape->type == _CYLINDER && rt->is_inside == true)
		return (true);
	if (get_cos(rt->normal, rt->hit_point_to_light) <= GRADIENT_END)
		return (false);
	return (true);
}

static bool	check_intersection_with_shapes(t_vector *ray, t_shapes *shapes,
	t_intersection *fct_ptr_array, t_ray_tracing *rt)
{
	t_shapes	*shape;
	t_vector	result;
	float		ret;

	shape = shapes;
	while (shape)
	{
		if (check_conditions(rt, shape, ray) == true)
		{
			ret = fct_ptr_array[shape->type](shape, ray);
			if (ret != -1.0f)
			{
				result = multiply_vector(*ray, ret);
				if (length(result) <= length(*ray))
					return (true);
			}
		}
		shape = shape->next;
	}
	return (false);
}

static t_vector	generate_grid_shadow_ray(const t_vector *ray,
	t_jittering_grid *grid)
{
	t_vector	shadow_ray;

	shadow_ray.origin = ray->origin;
	grid->offset_x = ((float)grid->x / (GRID_SIZE - 1) - 0.5f) * OFFSET_RATIO;
	grid->offset_y = ((float)grid->y / (GRID_SIZE - 1) - 0.5f) * OFFSET_RATIO;
	grid->offset_z = ((float)grid->z / (GRID_SIZE - 1) - 0.5f) * OFFSET_RATIO;
	shadow_ray.dir.x = ray->dir.x + grid->offset_x;
	shadow_ray.dir.y = ray->dir.y + grid->offset_y;
	shadow_ray.dir.z = ray->dir.z + grid->offset_z;
	return (shadow_ray);
}

void	jittered_grid(t_scene *scene, t_ray_tracing *raytracer,
						t_jittering_grid *grid)
{
	t_vector			shadow_ray;

	ft_memset(&shadow_ray, 0, sizeof(shadow_ray));
	grid->x = -1;
	while (++grid->x < GRID_SIZE)
	{
		grid->y = -1;
		while (++grid->y < GRID_SIZE)
		{
			grid->z = -1;
			while (++grid->z < GRID_SIZE)
			{
				shadow_ray = generate_grid_shadow_ray(
						&raytracer->hit_point_to_light, grid);
				if (check_intersection_with_shapes(&shadow_ray, scene->shapes,
						scene->intersection, raytracer))
					grid->shadow_hits++;
			}
		}
	}
	grid->shadow_factor = (float)(NB_OF_RAY - grid->shadow_hits) / NB_OF_RAY;
}
