/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:41:07 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/constant.h"

/*
	@dev:	Initializes a series of instruction arrays for various shapes and
			scene components (e.g., ambient light, camera, light, sphere,
			cylinder, and plane). Each instruction array defines the sequence
			of parsing operations that need to be performed for the respective
			component. These instructions are used in conjunction with a
			function pointer array to ensure the parsing logic is executed
			in the correct order.

			The instruction arrays specify steps such as skipping spaces,
			parsing coordinates, handling orientation and size, and processing
			RGB values. This modular approach simplifies parsing logic for
			different scene elements.
	@param:	p: a pointer to an array of pointers. Each entry in this array
			points to an instruction array corresponding to a specific scene
			element (e.g., ambient light, camera, etc.).
*/

static	void	init_instructions_2(int **p)
{
	static int	sphere[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, SIZE,
		SKIP_FLOAT, SKIP_SPACE, IS_DIGIT, RGB, SKIP_SPACE, EOL, END};
	static int	cylinder[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE,
		ORIENTATION, SKIP_SPACE, SIZE, SKIP_FLOAT, SKIP_SPACE,
		SIZE, SKIP_FLOAT, SKIP_SPACE, IS_DIGIT,
		RGB, SKIP_SPACE, EOL, END};
	static int	plane[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, ORIENTATION,
		SKIP_SPACE, IS_DIGIT, RGB, SKIP_SPACE, EOL, END};

	p[3] = cylinder;
	p[4] = plane;
	p[5] = sphere;
}

void	init_instructions(int **p)
{
	static int	ambient[] = {SKIP_SPACE, LIGHT_RATIO, SKIP_FLOAT, SKIP_SPACE,
		RGB, SKIP_SPACE, EOL, END};
	static int	camera[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, ORIENTATION,
		SKIP_SPACE, IS_DIGIT, FOV, SKIP_DIGIT, SKIP_SPACE, EOL, END};
	static int	light[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, IS_DIGIT,
		BRIGHTNESS, SKIP_FLOAT, SKIP_SPACE, IS_DIGIT, RGB,
		SKIP_SPACE, EOL, END};

	p[0] = ambient;
	p[1] = camera;
	p[2] = light;
	init_instructions_2(p);
}
