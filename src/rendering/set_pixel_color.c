/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:50:42 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/02 16:02:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/constant.h"
#include "../inc/types.h"
#include "../inc/operation.h"

/*
	@dev: Sets the color of a pixel based on the brightness
		  and the angle between the light direction and the
		  surface normal.

	@params: raytracer: The ray tracing object that holds
						the hit point and normal information.
			 brightness: A float representing the brightness
						 factor influencing the color.
			 color: A color structure that contains the RGB
					values to be set.

	@return: None.

	@behavior:
		1. Calculate the cosine of the angle between the
		   light vector and the normal.
		2. Set the alpha value of the color to 0 (transparent).
		3. If the cosine is above a threshold, set the color
		   to the provided color.
		4. If the cosine is within a gradient range, adjust
		   the color based on the brightness factor.
		5. If the cosine is below the gradient threshold,
		   set the color to transparent black.
*/

void	set_pixel_color(t_ray_tracing *raytracer, const float brightness,
	const color color)
{
	float	cos;
	float	brightness_factor;

	cos = get_cos(raytracer->hit_point_to_light, raytracer->normal);
	// raytracer->color.t_rgba.alpha = 0;
	if (cos >= 1.0 - brightness)
	{
		raytracer->color.t_rgba.red = color.t_rgba.red;
		raytracer->color.t_rgba.green = color.t_rgba.green;
		raytracer->color.t_rgba.blue = color.t_rgba.blue;
	}
	else if (cos < 1.0 - brightness && cos >= GRADIENT_END)
	{
		brightness_factor = (cos + (-1.0f * GRADIENT_END))
			/ (1.0f - brightness + (-1.0f * GRADIENT_END));
		raytracer->color.t_rgba.red = (uint8_t)((float)color.t_rgba.red
				* brightness_factor);
		raytracer->color.t_rgba.green = (uint8_t)((float)color.t_rgba.green
				* brightness_factor);
		raytracer->color.t_rgba.blue = (uint8_t)((float)color.t_rgba.blue
				* brightness_factor);
	}
	else if (cos < GRADIENT_END)
		raytracer->color.color = 0x00000000;
}
