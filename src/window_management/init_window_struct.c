/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/window_management.h"
#include "../inc/operation.h"
#include "../libft/inc/libft.h"

/*
	@dev: Initializes the `window` structure with settings based on
		  the scene and camera properties. This includes window size,
		  aspect ratio, viewport dimensions, and pixel-related vectors.

	@params: scene: A pointer to the scene containing camera details.
			 win:   A pointer to the window structure being initialized.

	@return: None.

	@behavior:
		1. Clear the `window` structure using `ft_memset`.
		2. Set the window width to a constant value `IMAGE_WIDTH`.
		3. Compute the window's aspect ratio based on defined width
		   and height ratios.
		4. Call `set_window_height` to determine the window's height
		   based on width and aspect ratio.
		5. Configure the viewport dimensions and field of view using
		   `set_viewport`.
		6. Set the viewport vectors based on the camera's orientation
		   using `set_viewport_vectors`.
		7. Determine the pixel delta values for ray tracing calculations.
		8. Calculate the position of the upper-left pixel of the viewport
		   based on the camera position and orientation.
		9. Set the location of the pixel at the origin of the viewport
		   (pixel 0,0) using `set_pixel00_loc`.
*/

void	init_window_struct(t_scene *scene, t_window *win)
{
	win->width = IMAGE_WIDTH;
	win->aspect_ratio = (float)WIDTH_RATIO / HEIGHT_RATIO;
	set_window_height((float)win->width, win->aspect_ratio, &win->height);
	set_viewport(win->width, win->height, &win->viewport,
		scene->camera.fov);
	set_viewport_vectors(&win->viewport, &win->viewport_vectors,
		&scene->camera.orientation);
	set_pixel_delta(win->width, win->height, &win->viewport_vectors,
		&win->pixel_delta);
	set_upper_left_pixel(scene->camera.coordinates,
		&win->viewport_vectors, scene->camera.orientation,
		&win->viewport_upper_left);
	set_pixel00_loc(&win->pixel_delta, win->viewport_upper_left,
		&win->pixel00_loc);
}
