/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel00_loc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"
#include "../../inc/operation.h"

/*
	@dev: Calculates the location of the origin pixel (0,0) on the
		  viewport by adjusting the upper-left corner with the pixel
		  delta values.

	@params: pixel_delta: A 2D array of vectors representing the
							pixel deltas in the U and V directions.
			 viewport_upper_left: The coordinates of the upper-left
								  corner of the viewport.
			 pixel00_loc: A pointer to a point structure where the
						  computed location of the (0,0) pixel will
						  be stored.

	@return: None.

	@behavior:
		1. Add the U and V pixel delta vectors to get a temporary vector
		   representing the combined delta movement.
		2. Update `pixel00_loc` by setting it to half the magnitude of
		   this combined delta.
		3. Add this delta to the `viewport_upper_left` to get the final
		   location of the origin pixel.
*/

void	set_pixel00_loc(t_vector (*pixel_delta)[2],
	t_point viewport_upper_left, t_point *pixel00_loc)
{
	t_vector	tmp;

	tmp = add_vector((*pixel_delta)[U], (*pixel_delta[V]));
	*pixel00_loc = tmp.dir;
	*pixel00_loc = multiply_point(*pixel00_loc, 0.5f);
	*pixel00_loc = add_point(viewport_upper_left, *pixel00_loc);
}
