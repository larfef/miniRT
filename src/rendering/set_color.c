/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:58:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:23:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"
#include <stdint.h>
#include "../../inc/types.h"

/*
	@dev: Creates a color structure using RGB float values.
		  Converts the floating-point values to 8-bit
		  unsigned integers for red, green, and blue.

	@params: r: Red channel as a float value [0, 1].
			 g: Green channel as a float value [0, 1].
			 b: Blue channel as a float value [0, 1].

	@return: A color struct containing the specified
			 red, green, and blue channels.

	@behavior:
		1. Each float color component is multiplied by 255.999
		   to fit into an 8-bit unsigned integer.
		2. The red, green, and blue values are set in the
		   color struct.
		3. Alpha is set to 0.
*/

color	set_color(const float r, const float g, const float b)
{
	color	color;

	color.t_rgba.red = (uint8_t)(255.999 * r);
	color.t_rgba.green = (uint8_t)(255.999 * g);
	color.t_rgba.blue = (uint8_t)(255.999 * b);
	color.t_rgba.alpha = 0x00;
	return (color);
}

/*
	@dev: Generates a sky-like color based on the direction
		  of a ray, creating a gradient effect.

	@params: direction: Pointer to a vector representing
						the ray direction.

	@return: A color struct representing the RGB color for
			 the given ray direction.

	@behavior:
		1. Normalizes the direction vector.
		2. Calculates an interpolation value `a` using the
		   ray’s y-component.
		3. Interpolates between two colors (white and a sky
		   blue gradient) using `a`.
		4. Returns the resulting color.
*/

color	ray_color(t_vector *direction)
{
	float		a;
	float		rgb[3];

	normalize(direction);
	a = 0.5f * (direction->dir.y + 1.0f);
	rgb[0] = ((1.0f - a) * 1.0f) + (a * 0.5f);
	rgb[1] = ((1.0f - a) * 1.0f) + (a * 0.7f);
	rgb[2] = ((1.0f - a) * 1.0f) + (a * 1.0f);
	return (set_color(rgb[0], rgb[1], rgb[2]));
}
