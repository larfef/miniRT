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

t_vector	unit_vector(t_vector *a)
{
	float	len;

	len = length(a);
	//fix for -0 value if needed
//	if (a->x == -0.0f) a->x = 0.0f;
//	if (a->y == -0.0f) a->y = 0.0f;
//	if (a->z == -0.0f) a->z = 0.0f;
	return (multiply_vector(*a, 1 / len));
}
