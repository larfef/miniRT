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

#include "../../inc/types.h"

/*
 	@dev: cross product implementation between two 3d vectors
 	@dev: vector must share the same origin
 	@param: a: first vector
 	@param: b: second vector
*/

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.dir.x = (a.dir.y * b.dir.z) - (a.dir.z * b.dir.y);
	result.dir.y = (a.dir.z * b.dir.x) - (a.dir.x * b.dir.z);
	result.dir.z = (a.dir.x * b.dir.y) - (a.dir.y * b.dir.x);
	return (result);
}
