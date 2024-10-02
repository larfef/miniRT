/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_upper_left_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"
#include "../libft/inc/libft.h"

/*
	@dev: Calculates the position of the upper left pixel in the viewport
		  based on the camera's center and the viewport vectors.

	@params: camera_center: A point representing the center of the camera.
			 viewport_vectors: A pointer to an array of vectors representing
							   the horizontal (U) and vertical (V) directions
							   of the viewport.
			 w: A vector representing the camera's orientation direction.
			 pos: A pointer to a point where the calculated upper left
				  pixel position will be stored.

	@return: None.

	@behavior:
		1. Initialize a vector to store the upper left pixel position.
		2. Calculate half the U and V viewport vectors to determine
		   the offsets from the camera center.
		3. Calculate the initial upper left pixel position by adding
		   the camera's center to the direction vector `w`.
		4. Adjust the upper left pixel position by subtracting the half
		   viewport vectors to shift to the correct location.
		5. Store the final position in the provided pointer `pos`.
*/

void	set_upper_left_pixel(t_point camera_center,
	t_vector (*viewport_vectors)[2], t_vector w, t_point *pos)
{
	t_vector	upper_left_pixel;
	t_vector	half_viewport_u;
	t_vector	half_viewport_v;

	ft_memset(&upper_left_pixel, 0, sizeof(upper_left_pixel));
	half_viewport_u = multiply_vector((*viewport_vectors)[0], 0.5f);
	half_viewport_v = multiply_vector((*viewport_vectors)[1], 0.5f);
	upper_left_pixel.dir = add_point(camera_center, w.dir);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_u);
	upper_left_pixel = sub_vector(upper_left_pixel, half_viewport_v);
	*pos = upper_left_pixel.dir;
}
