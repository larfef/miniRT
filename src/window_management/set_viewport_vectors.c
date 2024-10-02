/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewport_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 21:24:46 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"
#include "../../inc/operation.h"
#include "../libft/inc/libft.h"

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

void	set_viewport_vectors(float (*viewport)[2],
	t_vector (*viewport_vectors)[2], t_vector *w)
{
	t_vector	vup;
	t_vector	u;
	t_vector	minus_v;

	ft_memset(&u, 0, sizeof(u));
	vup = get_vup(w);
	u = cross_product(vup, *w);
	normalize(&u);
	minus_v = cross_product(*w, u);
	minus_v = multiply_vector(minus_v, -1);
	normalize(&minus_v);
	(*viewport_vectors)[U] = multiply_vector(u, (*viewport)[WIDTH]);
	(*viewport_vectors)[V] = multiply_vector(minus_v, (*viewport)[HEIGHT]);
}
