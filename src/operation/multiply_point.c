/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:52:10 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Multiplies a point's coordinates by a scalar.

	@param: a: The t_point to be multiplied.
	@param: n: The scalar multiplier.

	@return: The resulting t_point after multiplication.
*/

t_point	multiply_point(const t_point a, const float n)
{
	t_point	result;

	result.x = a.x * n;
	result.y = a.y * n;
	result.z = a.z * n;
	return (result);
}
