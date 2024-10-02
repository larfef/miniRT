/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light_ratio_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:45:58 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../../inc/constant.h"

/*
	@dev:	Validates the light ratio parsed from the scene description file.
			The light ratio represents the intensity or contribution of a light
			source in the scene (ambient light in particular). It ensures that
			the value is within an acceptable range and, if valid, assigns it
			to the corresponding field in the scene structure.

	@param:	line: A pointer to the string being parsed, representing the light
			ratio value. The function updates this pointer to skip over the
			parsed characters if `option` is set to `PARSE`.
	@param:	scene: A pointer to the scene structure where the validated light
			ratio value will be stored (specifically in the ambient light
			section).
	@param:	option: Specifies the mode of operation. If `option == PARSE`, the
			function is in parsing mode and validates the string length and
			value. If `option == _AMBIENT`, the function updates the scene's
			ambient light ratio.

	@behavior:
		1. If `option == PARSE`, checks that the light ratio string does not
		   exceed the defined `LEN_MAX` using `is_length_valid()`.
		2. Converts the string to a floating-point value using `ft_atof()`.
		3. If `option == _AMBIENT`, assigns the parsed value to the ambient
		   light's `light_ratio` field in the scene structure.
		4. If `option == PARSE`, advances the `line` pointer by 3 characters
		   to skip the parsed portion.
		5. If `option == PARSE`, checks that the light ratio is within the
		   allowed range, between `LIGHT_RATIO_MIN` and `LIGHT_RATIO_MAX`.
		6. Returns `true` if the value is valid, or `false` if it is invalid
		   or out of bounds.

	@return:	Returns `true` if the light ratio is valid and within the
				specified range, or `false` if the value is invalid or out of
				bounds.
*/

bool	is_light_ratio_valid(char **line, t_scene *scene, int option)
{
	float		tmp;

	if (option == PARSE
		&& !is_length_valid(*line, LEN_MAX))
		return (false);
	tmp = ft_atof(*line);
	if (option == _AMBIENT)
		scene->ambient.light_ratio = tmp;
	if (option == PARSE
		&& (tmp < LIGHT_RATIO_MIN
			|| tmp > LIGHT_RATIO_MAX))
		return (false);
	return (true);
}
