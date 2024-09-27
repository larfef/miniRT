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

void	parse_line(t_file *file)
{
	skip_space(&file->line, NULL, 0);
	set_current_line_type(file);
	if (file->current_line == NEWLINE)
		return ;
	if (file->current_line == INVALID)
		__exit(file, E_INVALID_LINE);
	is_duplicate(file);
	skip_line_start((int)file->current_line, &file->line);
	if (!is_line_valid(file->instructions, file))
		__exit(file, E_INVALID_LINE);
	set_duplicate_check(file);
}
