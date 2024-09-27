/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_of_line_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:44:00 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../inc/types.h"

/*
	@dev:	Validates whether the end of a line in the scene description
			is properly formatted. The function checks if the current line
			is empty or contains only a newline character, indicating that
			the line has no remaining data to process.

	@param:	line: A pointer to the string representing the current line
			in the scene description. The function checks the first character
			of this line to determine its validity.
	@param:	scene: A pointer to the `t_scene` structure, which is unused
			in this function but is included for consistency with the
			function signature.
	@param:	option: An integer parameter that is also unused in this
			function, maintaining compatibility with similar validation
			functions.

	@return:	Returns `true` if the line is considered valid (either empty
				or containing only a newline), or `false` if there is
				remaining content in the line to process.
*/

bool	is_end_of_line_valid(char **line, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	if (!(**line)
		|| **line == '\n')
		return (true);
	return (false);
}
