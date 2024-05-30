/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:20:51 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"

void	parse_line(t_file *file)
{
	skip_space(&file->line);
	set_current_line_type(file);
	if (file->current_line == NEWLINE)
		return ;
	if (file->current_line == INVALID)
		__exit(file, E_INVALID_LINE);
	is_duplicate(file);
	if (file->parsing_functions[file->current_line](file->line))
		__exit(file, E_INVALID_LINE);
	set_duplicate_check(file);
	return ;
}
