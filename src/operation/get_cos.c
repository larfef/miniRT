/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:48:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/operation.h"

/*
	@dev:	Calculates the cosine of the angle between two vectors.

	@param: a: The first t_vector.
	@param: b: The second t_vector.

	@return: The cosine value as a float.
*/

float	get_cos(const t_vector a, const t_vector b)
{
	float	len_a;
	float	len_b;
	float	product;
	float	result;

	len_a = length(a);
	len_b = length(b);
	product = dot_product(a, b);
	result = product / (len_a * len_b);
	return (result);
}
