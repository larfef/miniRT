/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev: 3d vectors dot product implementation
 	@dev: vectors must share the same origin
 	@param: a: vector struct
 	@param: b: vector struct
*/

float	dot_product(t_vector a, t_vector b)
{
	return ((a.dir.x * b.dir.x) + (a.dir.y * b.dir.y) + (a.dir.z * b.dir.z));
}
