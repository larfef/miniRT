/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_brightness_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:42:28 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

/*
	@dev:	Validates and optionally parses the brightness value from the input
			line. Depending on the `option` parameter, this function either
			checks the brightness value's validity (in the case of `PARSE`), or
			it assigns the value to the scene's light structure if the parsing
			is not required.

	@param:	line:	Pointer to the line in the scene description from which the
					brightness value is extracted. The `*line` is parsed to get
					the brightness value.
	@param:	scene:	Pointer to the `t_scene` structure. If the `option` parameter
					is not `PARSE`, the brightness value will be stored in
					`scene->light.brightness`.
	@param:	option:	Specifies the mode of the function. If `option == PARSE`,
					the function checks the validity of the brightness value
					(ensuring it's between 0 and 1). If `option != PARSE`, the
					parsed brightness value is stored in the scene.

	@return:	Returns `true` if the brightness is valid (or successfully parsed
				and assigned), otherwise returns `false` if the brightness is
				outside the valid range.
*/

bool	is_brightness_valid(char **line, t_scene *scene, int option)
{
	float	brightness;

	if (option == PARSE
		&& !is_length_valid(*line, LEN_MAX))
		return (1);
	brightness = ft_atof(*line);
	if (option == PARSE
		&& (brightness < 0 || brightness > 1))
		return (false);
	if (option != PARSE)
		scene->light.brightness = brightness;
	return (true);
}
