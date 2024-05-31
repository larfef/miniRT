/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:58:14 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:41:40 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing_constant.h"

static	void	init_instructions_2(int **p)
{
	static int	sphere[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, SKIP_FLOAT,
		SKIP_SPACE, IS_DIGIT, RGB, SKIP_SPACE, EOL, END};
	static int	cylinder[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE,
		ORIENTATION, SKIP_SPACE, SKIP_FLOAT, SKIP_SPACE,
		SKIP_FLOAT, SKIP_SPACE, IS_DIGIT,
		RGB, SKIP_SPACE, EOL, END};
	static int	plane[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, ORIENTATION,
		SKIP_SPACE, IS_DIGIT, RGB, SKIP_SPACE, EOL, END};

	p[3] = cylinder;
	p[4] = plane;
	p[5] = sphere;
}

void	init_instructions(int **p)
{
	static int	ambient[] = {SKIP_SPACE, LIGHT_RATIO, SKIP_SPACE,
		RGB, EOL, END};
	static int	camera[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, ORIENTATION,
		SKIP_SPACE, IS_DIGIT, FOV, SKIP_DIGIT, EOL, END};
	static int	light[] = {SKIP_SPACE, COORDINATES, SKIP_SPACE, IS_DIGIT,
		BRIGHTNESS, SKIP_FLOAT, SKIP_SPACE, IS_DIGIT, RGB, EOL, END};

	p[0] = ambient;
	p[1] = camera;
	p[2] = light;
	init_instructions_2(p);
}
