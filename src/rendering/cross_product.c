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

void	cross_product(vector *a, vector *b, vector *result)
{
	*result[X] = (*a[Y] * *b[Z]) - (*a[Z] * *b[Y]);
	*result[Y] = (*a[Z] * *b[X]) - (*a[X] * *b[Z]);
	*result[Z] = (*a[X] * *b[Y]) - (*a[Y] * *b[X]);
}
