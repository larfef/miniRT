/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_delta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"
#include "../../inc/operation.h"

/*
	@dev: Sets the pixel delta for the U and V directions by scaling
		  the viewport vectors according to the image's width and height.

	@params: image_width: The width of the rendered image in pixels.
			 image_height: The height of the rendered image in pixels.
			 viewport_vectors: A pointer to an array of vectors representing
							   the horizontal (U) and vertical (V) directions
							   of the viewport.
			 pixel_delta: A pointer to an array of vectors that will store
						  the calculated pixel deltas for both U and V.

	@return: None.

	@behavior:
		1. Scale the U-direction viewport vector by the inverse of the
		   image width to calculate the horizontal pixel delta.
		2. Scale the V-direction viewport vector by the inverse of the
		   image height to calculate the vertical pixel delta.
*/

void	set_pixel_delta(int32_t image_width, int32_t image_height,
	t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2])
{
	(*pixel_delta)[U] = multiply_vector((*viewport_vectors)[U],
			(1 / (float)image_width));
	(*pixel_delta)[V] = multiply_vector((*viewport_vectors)[V],
			(1 / (float)image_height));
}
