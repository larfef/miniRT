/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  unit_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:19:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:05:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"

/*
	@dev:	Normalizes a vector's direction.

	@param: a: Pointer to the t_vector to normalize.

	@return: None (modifies the vector in place).
*/

void	normalize(t_vector *a)
{
	float	len;

	len = length(*a);
	if (len > 0)
	{
		a->dir.x /= len;
		a->dir.y /= len;
		a->dir.z /= len;
	}
}
