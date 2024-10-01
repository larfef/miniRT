/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:23:55 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Performs a component-wise addition of two 3D points. The function
			adds the x, y, and z components of two t_point structures and
			returns the resulting point.

	@param: a: The first 3D point (t_point) used in the addition.
	@param: b: The second 3D point (t_point) used in the addition.

	@return: A t_point representing the sum of the x, y, and z components
			 of the two input points.
*/

t_point	add_point(const t_point a, const t_point b)
{
	t_point	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}
