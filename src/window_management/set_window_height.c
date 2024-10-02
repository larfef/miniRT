/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/*
	@dev: Computes the U and V viewport vectors based on the camera's
		  orientation and the up vector, storing them in the provided
		  viewport vector array.

	@params: viewport: A pointer to an array containing the width and
					  height of the viewport.
			 viewport_vectors: A pointer to an array where the
							   resulting U and V viewport vectors will be stored.
			 w: A pointer to a vector representing the camera's
				direction.

	@return: None.

	@behavior:
		1. Retrieve the up vector using the camera's direction `w`.
		2. Compute the U vector by taking the cross product of the up
		   vector and the direction vector `w`.
		3. Normalize the U vector to ensure it has a unit length.
		4. Calculate the negative V vector by taking the cross product
		   of the direction vector `w` and the U vector, then normalize it.
		5. Store the U and V vectors in the `viewport_vectors` array,
		   scaling them by the viewport's width and height.
*/

void	set_window_height(const float width, const float aspect_ratio, int *height)
{
	*height = (int)roundf(width / aspect_ratio);
	if (*height < 1)
		*height = 1;
}
