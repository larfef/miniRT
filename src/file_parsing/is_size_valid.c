/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_size_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:50:17 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../../inc/constant.h"

/*
	@dev:	Validates and parses the size of a shape in the scene.
			For cylinders, it ensures both the height and diameter
			are properly assigned. The size is validated to be a
			positive number and stored accordingly in the shape's
			structure if valid.

	@param:	line:	A double pointer to the input string containing
					the size value. The string is updated as values
					are parsed.
	@param:	scene:	A pointer to the `t_scene` structure, where the
					parsed size values are stored for the current
					shape.
	@param:	option:	A flag indicating the context in which the
					size is being parsed:
					- If `_SHAPES`, the size value is applied to the
					  current shape.
					- If `PARSE`, it ensures the size is positive
					  and correctly formatted.

	@behavior:
		1. Checks if the length of the input is valid using
		   `is_length_valid()`.
		2. Parses the size value using `ft_atof()`.
		3. For shapes that are not planes, assigns the parsed
		   size to either the height or diameter field, based
		   on the shape's type.
		4. If parsing a cylinder, alternates between height
		   and diameter for each call.
		5. Ensures the parsed size is greater than 0.

	@return:	Returns `true` if the size is valid and greater
				than 0; otherwise, returns `false` for invalid
				values or incorrect formatting.
*/

bool	is_size_valid(char **line, t_scene *scene, int option)
{
	float		tmp;
	static int	i;

	if (option == PARSE && !is_length_valid(*line, LEN_MAX))
		return (false);
	tmp = ft_atof(*line);
	if (option == PARSE
		&& tmp <= 0.0)
		return (false);
	if (option == _SHAPES && scene->shapes->type != _PLANE)
	{
		if (i == HEIGHT)
		{
			scene->shapes->size[HEIGHT] = tmp;
			i = DIAMETER;
		}
		else if (i == DIAMETER)
		{
			scene->shapes->size[DIAMETER] = tmp;
			if (scene->shapes->type == _CYLINDER)
				i = HEIGHT;
		}
	}
	return (true);
}
