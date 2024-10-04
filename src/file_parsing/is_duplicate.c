/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:43:09 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/constant.h"

/*
	@dev:	Checks for duplicate entries in the scene description based on
			the current line number. If the current line is less than 3 and
			a minimal scene element exists for that line, the function
			triggers an exit with an error code indicating a duplicate entry.

	@param:	file: A pointer to the `t_file` structure, which contains
			information about the current line being processed and the
			minimal scene elements for validation.

	@return:	Returns `false` if no duplicates are detected. If a duplicate
				is found (i.e., the current line is less than 3 and there is
				an existing minimal scene entry), the function will call
				`__exit` to terminate the program with an error message.
*/

bool	is_duplicate(t_file *file)
{
	if (file->current_line < 3 && file->minimal_scene[file->current_line])
		__exit(file, E_DUP);
	return (false);
}
