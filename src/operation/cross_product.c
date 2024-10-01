/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../libft/inc/libft.h"

/*
	@dev:	Calculates the cross product of two 3D vectors. The cross product
			of two vectors results in a vector that is orthogonal (perpendicular)
			to both input vectors. This is commonly used in graphics and physics
			to determine the normal vector to a surface defined by the two
			vectors.

	@param: a: The first t_vector input, representing the first vector.
	@param: b: The second t_vector input, representing the second vector.

	@return: A t_vector representing the cross product of the two input vectors,
			 with its direction determined by the right-hand rule.
*/

t_vector	cross_product(const t_vector a, const t_vector b)
{
	t_vector	result;

	ft_memset(&result, '\0', sizeof(result));
	result.dir.x = (a.dir.y * b.dir.z) - (a.dir.z * b.dir.y);
	result.dir.y = (a.dir.z * b.dir.x) - (a.dir.x * b.dir.z);
	result.dir.z = (a.dir.x * b.dir.y) - (a.dir.y * b.dir.x);
	return (result);
}
