/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Subtracts two vectors.

	@param: a: The minuend vector.
	@param: b: The subtrahend vector.

	@return: The resulting vector after subtraction.
*/

t_vector	sub_vector(const t_vector a, const t_vector b)
{
	t_vector	result;

	result.origin.x = a.origin.x - b.origin.x;
	result.origin.y = a.origin.y - b.origin.y;
	result.origin.z = a.origin.z - b.origin.z;
	result.dir.x = a.dir.x - b.dir.x;
	result.dir.y = a.dir.y - b.dir.y;
	result.dir.z = a.dir.z - b.dir.z;
	return (result);
}
