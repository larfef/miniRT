/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rendering.h"
#include "math.h"

t_vector	cross_product(t_vector *a, t_vector *b)
{
	t_vector	result;

	result.x = (a->y * b->z) - (a->z * b->y);
	result.y = (a->z * b->x) - (a->x * b->z);
	result.z = (a->x * b->y) - (a->y * b->x);
	return (result);
}
