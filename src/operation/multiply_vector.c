/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Multiplies a vector's origin and direction by a scalar.

	@param: a: The t_vector to be multiplied.
	@param: n: The scalar multiplier.

	@return: The resulting t_vector after multiplication.
*/

t_vector	multiply_vector(const t_vector a, const float n)
{
	t_vector	result;

	result.origin.x = a.origin.x * n;
	result.origin.y = a.origin.y * n;
	result.origin.z = a.origin.z * n;
	result.dir.x = a.dir.x * n;
	result.dir.y = a.dir.y * n;
	result.dir.z = a.dir.z * n;
	return (result);
}
