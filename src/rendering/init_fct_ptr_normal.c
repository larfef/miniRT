/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fct_ptr_normal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:31:40 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/03 18:45:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/types.h"
#include "../inc/rendering.h"

/*
	@dev: Initializes an array of function pointers that
		  set normal vectors for different shapes
		  (cylinder, plane, sphere).

	@params: fct_ptr: A pointer to an array of function
					  pointers, where each function will
					  set the normal vector for a shape.

	@return: None.

	@behavior:
		1. Assign the `set_cylinder_normal_vector` function
		   to the first index of the function pointer array.
		2. Assign the `set_plane_normal_vector` function to
		   the second index.
		3. Assign the `set_sphere_normal_vector` function
		   to the third index.
*/

void	init_fct_ptr_normal(fct_ptr_normal *fct_ptr)
{
	fct_ptr[0] = set_cylinder_normal_vector;
	fct_ptr[1] = set_plane_normal_vector;
	fct_ptr[2] = set_sphere_normal_vector;
}
