/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_vector                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev: multiply a vector by a float.
 	@param: a: the vector to multiply
 	@param: n: the number to multiply the vector by.
 */

t_vector	multiply_vector(t_vector *a, float n)
{
	t_vector	result;

	result.origin.x = a->origin.x * n;
	result.origin.y = a->origin.y * n;
	result.origin.z = a->origin.z * n;
	result.dir.x = a->dir.x * n;
	result.dir.y = a->dir.y * n;
	result.dir.z = a->dir.z * n;
	return (result);
}
