/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_center.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:15:44 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 21:18:21 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/constant.h"
#include "../../inc/types.h"
#include "../../inc/operation.h"

/*
	@dev: Calculates the center of a pixel on the viewport by
		  adjusting the origin location based on the pixel's position
		  and delta values.

	@params: win: A pointer to the window structure containing the
				  viewport information and pixel deltas.
			 pixel_center: A pointer to a point structure where the
						   calculated pixel center will be stored.

	@return: None.

	@behavior:
		1. Multiply the U pixel delta by the pixel's X position to get
		   the horizontal movement.
		2. Multiply the V pixel delta by the pixel's Y position to get
		   the vertical movement.
		3. Add these movements together to get the offset from the
		   origin.
		4. Add the origin location (`pixel00_loc`) to the offset to get
		   the final pixel center location.
*/

void	set_pixel_center(t_window *win, t_point *pixel_center)
{
	*pixel_center = add_point(multiply_point(win->pixel_delta[U].dir,
			(float)win->x), multiply_point(win->pixel_delta[V].dir,
				(float)win->y));
	*pixel_center = add_point(*pixel_center, win->pixel00_loc);
}
