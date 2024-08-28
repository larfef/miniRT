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
 * @dev: utility function to set a gradient background color
 */

color	set_color(float r, float g, float b)
{
	color	color;

	color.t_rgba.red = (uint8_t)(255.999 * r);
	color.t_rgba.green = (uint8_t)(255.999 * g);
	color.t_rgba.blue = (uint8_t)(255.999 * b);
	color.t_rgba.alpha = 0x00;
	return (color);
}

color ray_color(t_vector *direction)
{
	float		a;
	float		rgb[3];

	normalize(direction);
	a = 0.5 * (direction->dir.y + 1.0);
	rgb[0] = ((1.0 - a) * 1.0) + (a * 0.5);
	rgb[1] = ((1.0 - a) * 1.0) + (a * 0.7);
	rgb[2] = ((1.0 - a) * 1.0) + (a * 1.0);
	return (set_color(rgb[0], rgb[1], rgb[2]));
}
