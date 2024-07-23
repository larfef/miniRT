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
	@dev: normalize (vector length equal to 1 unit length) a given vector
 	@param: a: vector struct
*/

void	normalize(t_vector a)
{
	float	len;

	len = length(a);
	if (len > 0)
	{
		a.dir.x /= len;
		a.dir.y /= len;
		a.dir.z /= len;
	}
}
