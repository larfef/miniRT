/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:15:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 16:17:53 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/types.h"
#include "../inc/operation.h"
#include "../inc/rendering.h"
#include "../inc/constant.h"
#include "../libft/inc/libft.h"

/*
	@dev: Sets the intersection point of the ray on the shape
		  based on the camera position and the ray's solution.

	@params: raytracer: A pointer to a `t_ray_tracing` structure
				containing the camera and ray information.

	@return: None.

	@behavior:
		1. Calculate the intersection point by adding the
		   camera position to the scaled ray direction.
		2. Store the resulting point in `hit_point_to_light.origin`.
*/

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_point(
			raytracer->camera_to_viewport.origin,
			multiply_point(raytracer->camera_to_viewport.dir,
				raytracer->solution));
}

/*
	@dev: Adjusts the RGB values of a color based on the shadow
		  factor to simulate shadows in the rendering.

	@params: color: A pointer to a `color` structure whose RGB
					values will be modified.
			  shadow_factor: A factor between 0 and 1 to
						  determine the strength of the shadow.

	@return: None.

	@behavior:
		1. Multiply the red, green, and blue components of
		   the color by the shadow factor.
		2. Store the modified values back in the color structure.
*/

void	set_shadow_color(t_color *color, const float shadow_factor)
{
	color->t_rgba.red = (uint8_t)(((float)color->t_rgba.red) * shadow_factor);
	color->t_rgba.green = (uint8_t)(((float)color->t_rgba.green)
			* shadow_factor);
	color->t_rgba.blue = (uint8_t)(((float)color->t_rgba.blue) * shadow_factor);
}

/*
	@dev: Modifies the ambient color based on the specified
		  ambient factor for rendering purposes.

	@params: rt: A pointer to a `t_ray_tracing` structure
				containing the current color and ambient info.
			  color: The base color to apply ambient lighting to.
			  ambient_factor: A factor determining how much ambient
					  light affects the color.

	@return: None.

	@behavior:
		1. Set the current color to the specified ambient color.
		2. Multiply the RGB components of the color by the ambient
		   factor to adjust the brightness based on ambient lighting.
*/

void	set_ambient_color(t_ray_tracing *rt, const uint32_t color,
	const float ambient_factor)
{
	rt->color.color = color;
	rt->color.t_rgba.red = (uint8_t)((float)rt->color.t_rgba.red
			* ambient_factor);
	rt->color.t_rgba.green = (uint8_t)((float)rt->color.t_rgba.green
			* ambient_factor);
	rt->color.t_rgba.blue = (uint8_t)((float)rt->color.t_rgba.blue
			* ambient_factor);
}

/*
	@dev: Traces rays from the camera through the scene to
		  calculate colors at the intersection points with shapes.

	@params: scene: A pointer to the scene structure containing
					lighting and object information.
			  rt: A pointer to a `t_ray_tracing` structure that
				  stores ray-tracing data.

	@return: None.

	@behavior:
		1. Initialize a jittered grid for antialiasing.
		2. Check if there is a valid intersection with a shape.
		3. Calculate the intersection point and light direction.
		4. Set the normal vector for the shape at the intersection.
		5. Calculate the pixel color based on the light brightness.
		6. If the angle between the light and normal is greater
		   than a threshold, apply jittered for antialiasing.
		7. Set the final shadow-adjusted color.
		8. If no intersection occurs, set the ambient color.
*/

void	trace_rays(t_scene *scene, t_ray_tracing *rt)
{
	t_jittering_grid	grid;
	t_vector			camera_to_hit_point;

	ft_memset(&grid, 0, sizeof(grid));
	rt->is_inside = false;
	if (rt->solution > 0.0f && !scene->light_hidden)
	{
		camera_to_hit_point = multiply_vector(rt->camera_to_viewport,
				rt->solution);
		rt->distance_from_camera = length(camera_to_hit_point);
		set_intersection_point(rt);
		rt->hit_point_to_light.dir = sub_point(
				scene->light.coordinates,
				rt->hit_point_to_light.origin);
		rt->set_normal_vector[rt->shape->type](rt);
		set_pixel_color(rt, scene->light.brightness, rt->shape->color);
		if (get_cos(rt->hit_point_to_light, rt->normal) > GRADIENT_END)
			jittered_grid(scene, rt, &grid);
		set_shadow_color(&rt->color, grid.shadow_factor);
	}
	else if (rt->solution > 0.0f)
		rt->color.color = 0;
	else
		set_ambient_color(rt, scene->ambient.color.color,
			scene->ambient.light_ratio);
}
