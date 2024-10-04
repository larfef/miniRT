/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:50:53 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/constant.h"

/*
	@dev: Parses a line from the file specified in the `t_file`
			structure. This function processes the line by skipping
			leading whitespace, determining its type, checking for
			duplicates, and validating its contents. It updates
			the minimal scene elements accordingly.

	@param:	file: A pointer to the `t_file` structure that
			contains information about the current line being
			parsed, its type, and instructions for validation.

	@behavior:
		1. Calls `skip_space` to remove leading whitespace from
		   the current line.
		2. Calls `set_current_line_type` to determine the type of
		   the current line (e.g., NEWLINE, INVALID).
		3. If the line type is NEWLINE, the function returns early
		   without further processing.
		4. If the line type is INVALID, it exits the program with
		   an error indicating an invalid line format.
		5. Checks for duplicate entries using `is_duplicate`.
		6. Calls `skip_line_start` to advance the pointer past
		   the beginning of the line based on its type.
		7. Validates the line's contents against the expected format
		   using `is_line_valid`. If validation fails, it exits
		   with an error.
		8. If the current line is less than MANDATORY_ELEM, it
		   marks it as a minimal scene element.

	@return: None. The function may terminate the program if
			 an error occurs during parsing.
*/

void	parse_line(t_file *file)
{
	skip_space(&file->line, NULL, 0);
	set_current_line_type(file);
	if (file->current_line == NEWLINE)
		return ;
	if (file->current_line == INVALID)
		__exit(file, E_INVALID_LINE);
	is_duplicate(file);
	skip_line_start(file->current_line, &file->line);
	if (!is_line_valid(file->instructions, file))
		__exit(file, E_INVALID_LINE);
	if (file->current_line < MANDATORY_ELEM)
		file->minimal_scene[file->current_line] = true;
}
