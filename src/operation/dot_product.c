/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Calculates the dot product of two vectors.

	@param: a: The first t_vector.
	@param: b: The second t_vector.

	@return: The dot product as a float.
*/

float	dot_product(const t_vector a, const t_vector b)
{
	return ((a.dir.x * b.dir.x) + (a.dir.y * b.dir.y) + (a.dir.z * b.dir.z));
}
