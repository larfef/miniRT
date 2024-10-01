/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Performs a component-wise addition of two 3D vectors. The function
			adds both the origin and direction components (x, y, z) of two
			t_vector structures and returns the resulting vector.

	@param: a: The first 3D vector (t_vector) used in the addition.
	@param: b: The second 3D vector (t_vector) used in the addition.

	@return: A t_vector representing the sum of both the origin and direction
			 components of the two input vectors.
*/

t_vector	add_vector(const t_vector a, const t_vector b)
{
	t_vector	result;

	result.origin.x = a.origin.x + b.origin.x;
	result.origin.y = a.origin.y + b.origin.y;
	result.origin.z = a.origin.z + b.origin.z;
	result.dir.x = a.dir.x + b.dir.x;
	result.dir.y = a.dir.y + b.dir.y;
	result.dir.z = a.dir.z + b.dir.z;
	return (result);
}
