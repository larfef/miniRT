/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:51:46 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/types.h"

/*
	@dev: Determines the type of the current line in the `t_file` structure
			based on its content. The function checks the beginning of the
			line string to identify whether it corresponds to an ambient
			light, camera, light source, or one of the shapes (cylinder,
			plane, sphere). It sets the `current_line` member of the
			`t_file` structure to the appropriate type constant.

	@param:	file: A pointer to the `t_file` structure, which contains
			the line currently being processed and will be updated with
			the type of that line.

	@behavior:
		1. Checks the beginning of the `line` string for specific
		   prefixes to determine its type.
		2. Sets `file->current_line` to one of the following types:
			- `AMBIENT` for ambient light lines starting with "A ".
			- `CAMERA` for camera lines starting with "C ".
			- `LIGHT` for light source lines starting with "L ".
			- `CYLINDER` for cylinder lines starting with "cy ".
			- `PLANE` for plane lines starting with "pl ".
			- `SPHERE` for sphere lines starting with "sp ".
			- `NEWLINE` for empty lines (just a newline character).
			- `INVALID` for any lines that do not match the expected
			  types.

	@return: None. The function modifies the `current_line` member
			 directly within the `t_file` structure.
*/

void	set_current_line_type(t_file *file)
{
	if (!ft_strncmp(file->line, "A ", 1))
		file->current_line = AMBIENT;
	else if (!ft_strncmp(file->line, "C ", 1))
		file->current_line = CAMERA;
	else if (!ft_strncmp(file->line, "L ", 1))
		file->current_line = LIGHT;
	else if (!ft_strncmp(file->line, "cy ", 2))
		file->current_line = CYLINDER;
	else if (!ft_strncmp(file->line, "pl ", 2))
		file->current_line = PLANE;
	else if (!ft_strncmp(file->line, "sp ", 3))
		file->current_line = SPHERE;
	else if (*file->line == '\n')
		file->current_line = NEWLINE;
	else
		file->current_line = INVALID;
}
