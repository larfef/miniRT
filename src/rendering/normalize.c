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

#include "../../inc/window_management.h"
#include "../../inc/rendering.h"
#include <math.h>

float	length(t_vector *a)
{
	return (sqrt(dot_product(a, a)));
}

void	normalize(t_vector *a)
{
	float	len;

	len = length(a);
	if (len > 0)
	{
		a->x /= len;
		a->y /= len;
		a->z /= len;
	}
}
