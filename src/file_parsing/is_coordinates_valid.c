/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinates_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:42:51 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../../inc/constant.h"

/*
	@dev:	Validates and processes coordinates from the input string,
			storing them in the appropriate structure (camera, light, or shapes)
			based on the specified `option`. The function iterates through three
			components of the coordinate (x, y, z), checking their validity and
			format.

	@param:	p:	Pointer to the string containing the coordinates, which will
					be parsed. The `*p` is updated as the coordinates are
					read and skipped.
	@param:	scene: Pointer to the `t_scene` structure where the parsed
					coordinates will be stored, depending on the option.
	@param:	option: Specifies the context in which the function operates.
					- If `PARSE`, the function checks the format and validity
					of the coordinates.
					- If `_CAMERA`, `_LIGHT`, or `_SHAPES`, the parsed
					coordinates will be stored in the respective fields of
					`scene->camera`, `scene->light`, or `scene->shapes`.

	@return:	Returns `true` if the coordinates are valid and processed
				successfully. Returns `false` if the coordinates do not meet
				the specified requirements (e.g., invalid format or missing
				components).
*/

bool	is_coordinates_valid(char **p, t_scene *scene, int option)
{
	float		tmp;
	int			i;

	i = -1;
	while (++i != 3)
	{
		if (option != PARSE)
			tmp = ft_atof(*p);
		if (option == _CAMERA)
			set_float(tmp, (float *)&scene->camera.coordinates + i);
		if (option == _LIGHT)
			set_float(tmp, (float *)&scene->light.coordinates + i);
		if (option == _SHAPES)
			set_float(tmp, (float *)&scene->shapes->center + i);
		if (option == PARSE
			&& !is_length_valid(*p, 15))
			return (false);
		skip_float(p, NULL, 0);
		if (option == PARSE
			&& i < 2 && **p != ',')
			return (false);
		(*p)++;
	}
	return (true);
}
