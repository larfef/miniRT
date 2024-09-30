/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:49:08 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

/*
	@dev:	Validates and parses RGB color values for different scene
			components such as shapes and ambient light. Ensures that
			the RGB values are within the valid range [0, 255] and
			applies them to the corresponding scene structure if
			necessary.

	@param:	p:		A double pointer to the input string containing the
					RGB values. The string is updated as values are
					parsed.
	@param:	scene:	A pointer to the `t_scene` structure, where the
					RGB values are stored based on the `option` provided.
	@param:	option:	A flag indicating which scene component the RGB
					applies to:
					- If `_SHAPES`, the RGB values are assigned to the
					  current shape's color.
					- If `_AMBIENT`, the RGB values are applied to the
					  ambient light.
					- If `PARSE`, validation of the RGB values is done
					  without assigning them to the scene.

	@behavior:
		1. Iterates through the three RGB components (R, G, B).
		2. Parses each component using `ft_atoi()` and ensures the
		   value is within the valid range [0, 255].
		3. If `option` is `_SHAPES`, stores the RGB values in the
		   shape's color field.
		4. If `option` is `_AMBIENT`, stores the RGB values in the
		   ambient light's color field.
		5. If `PARSE`, checks that the values are properly formatted
		   and comma-separated for the first two components.
		6. Advances the pointer after each value and ensures it's
		   properly terminated.

	@return:	Returns `true` if the RGB values are valid and within
				the range [0, 255]; otherwise, returns `false` for
				invalid values or incorrect formatting.
*/

bool	is_rgb_valid(char **p, t_scene *scene, int option)
{
	int		i;
	int64_t	tmp;

	i = -1;
	while (++i != 3)
	{
		tmp = ft_atoi(*p);
		if (option == PARSE && !tmp && **p != '0')
			return (false);
		if (option == _SHAPES)
			scene->shapes->color.color |= (tmp & 0xFF) << (8 * (2 - i));
		if (option == _AMBIENT)
			scene->ambient.color.color |= (tmp & 0xFF) << (8 * (2 - i));
		if (option == PARSE
			&& (tmp < 0 || tmp > 255))
			return (false);
		skip_digit(p, NULL, 0);
		if (option == PARSE
			&& i < 2 && **p != ',')
			return (false);
		if (**p != '\0')
			(*p)++;
	}
	return (true);
}
