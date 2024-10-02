/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 20:55:51 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/operation.h"
#include "../libft/inc/libft.h"

/*
	@dev: Calculates the "up" vector (`vup`) used for camera orientation,
		  ensuring it is perpendicular to the provided vector `w`.

	@params: w: A pointer to the vector `w` representing the direction
				 the camera is looking at, which the "up" vector needs
				 to be perpendicular to.

	@return: A vector representing the "up" direction (`vup`).

	@behavior:
		1. Initialize the default `vup` direction as {0, 1, 0} (the Y-axis).
		2. Calculate the cross product of `vup` and `w` to check
		   if `vup` is perpendicular to `w`.
		3. If the length of the cross product result is near zero,
		   `vup` is parallel to `w`, so set `vup` to {1, 0, 0}.
		4. Normalize the `vup` vector to ensure it is a unit vector.
		5. Return the perpendicular and normalized `vup`.
*/

t_vector	get_vup(t_vector *w)
{
	t_vector	vup;
	t_vector	tmp;

	ft_memset(&vup, 0, sizeof(vup));
	vup.dir.y = 1;
	tmp = cross_product(vup, *w);
	if (length(tmp) < 1e-6)
		vup.dir = (t_point){1, 0, 0};
	normalize(&vup);
	return (vup);
}
