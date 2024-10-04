/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:46:32 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/constant.h"

/*
	@dev:	Validates a line in the scene description file by iterating through
			a set of parsing instructions. Each line in the file corresponds
			to a specific object or property (e.g., ambient light, camera,
			light, or shapes), and this function applies the appropriate
			parsing functions to check its validity.

	@param:	tab: A 2D array of integers, where each row represents the parsing
			instructions for a particular line type (e.g., ambient light,
			camera, etc.). The elements in the row are indices that map to
			parsing functions, and the row ends when `END` is encountered.
	@param:	file: A pointer to the `t_file` structure, which contains the
			current line being processed (`file->line`), the line's type
			(`file->current_line`), and an array of function pointers
			(`file->parsing_functions`) that correspond to the parsing functions.

	@behavior:
		1. Initializes a counter (`i`) and starts iterating over the instruction
		   set for the current line, as defined by `tab[file->current_line]`.
		2. For each instruction, it calls the corresponding parsing function
		   from `file->parsing_functions` using the index stored in `tab`.
		   - The parsing function is passed a pointer to the current line and
			 is executed in `PARSE` mode.
		3. If all instructions in the row are successfully parsed (i.e., until
		   `END` is encountered in `tab`), the function returns `true`,
		   indicating the line is valid.
		4. If any parsing function fails, the loop exits early and the function
		   returns `false`, indicating the line is invalid.

	@return:	Returns `true` if the line is valid and all parsing instructions
				are successfully executed; returns `false` if any parsing step
				fails.
*/

bool	is_line_valid(int **tab, t_file *file)
{
	uint8_t	i;

	i = -1;
	while (tab[file->current_line][++i] != END
		&& file->parsing_functions[tab[file->current_line][i]]
			(&file->line, NULL, PARSE));
	if (tab[file->current_line][i] == END)
		return (true);
	return (false);
}
