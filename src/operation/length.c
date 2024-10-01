/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:51:10 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include "../../inc/operation.h"
#include <math.h>

/*
	@dev:	Calculates the length (magnitude) of a vector.

	@param: a: The t_vector whose length is calculated.

	@return: The length of the vector as a float.
*/

float	length(const t_vector a)
{
	return ((float)sqrt((double)dot_product(a, a)));
}
