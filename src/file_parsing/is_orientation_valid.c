/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_orientation_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:48:33 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include <operation.h>

/*
	@dev:	Checks whether a given vector has been normalized. A vector is
			considered normalized if its length is exactly 1.

	@param: p:	The vector to be checked.

	@return: Returns true if the vector is normalized, false otherwise.
*/

static bool is_vector_normalized(const t_point p)
{
	t_vector	v = {0};

	v.dir = p;
	if (length(v) > 1.0f + UNIT_VECTOR_EPSILON
		|| length(v) < 1.0f - UNIT_VECTOR_EPSILON)
		return (false);
	return (true);
}

/*
	@dev:	Extracts the orientation value and assigns it to the appropriate
			part of the scene structure based on the option parameter.

	@param: scene: Pointer to the scene structure to update.
	@param: n: The float value of the current orientation component.
	@param: i: The index (0-2) of the component being updated.
	@param: option: Specifies if the orientation applies to a camera or shape.
*/

static void extract_orientation(t_scene *scene, const float n,
									const int i, const int option)
{
	if (option == _CAMERA)
		set_float(n, (float *)&scene->camera.orientation.dir + i);
	if (option == _SHAPES
		&& scene->shapes->type != _SPHERE)
		set_float(n, (float *)&scene->shapes->orientation.dir + i);
}

/*
	@dev:	Validates and extracts the orientation vector for a camera or shape.
			The function ensures that the orientation vector components are
			between -1 and 1, verifies the length of the input, and ensures
			the final vector is normalized (has a length of 1). It updates
			the appropriate structure (camera or shape) with the orientation
			data if not in parsing mode.

	@param: p:	Pointer to the string containing the orientation components.
	@param: scene: Pointer to the scene structure, containing the camera and
			shapes' data.
	@param: option: Specifies whether the orientation applies to a camera or
			shape, or if it is in parsing mode (PARSE).

	@return: Returns true if the orientation is valid, false otherwise.
*/

bool	is_orientation_valid(char **p, t_scene *scene, int option)
{
	float		tmp;
	int8_t		i;
	t_point		orientation = {0};

	i = -1;
	while (++i != 3)
	{
		if (option == PARSE
			&& !is_length_valid(*p, LEN_MAX))
			return (false);
		tmp = ft_atof(*p);
		if (option != PARSE)
			extract_orientation(scene, tmp, i, option);
		if (option == PARSE
			&& (tmp < -1 || tmp > 1))
			return (false);
		skip_float(p, NULL, 0);
		if (option == PARSE
			&& (i < 2 && **p != ','))
			return (false);
		*((float*)&orientation + i) = tmp;
		(*p)++;
	}
	return (is_vector_normalized(orientation));
}
