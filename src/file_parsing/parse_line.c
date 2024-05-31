/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:15:28 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"

void	skip_line_start(t_element_type type, char **p)
{
	if (type <= 2)
		(*p)++;
	else 
		*p += 3;
}

void	parse_line(t_file *file)
{
	static int	*tab[6];

	if (!*tab)
		init_instructions(tab);
	skip_space(&file->line);
	set_current_line_type(file);
	if (file->current_line == NEWLINE)
		return ;
	if (file->current_line == INVALID)
		__exit(file, E_INVALID_LINE);
	is_duplicate(file);
	skip_line_start(file->current_line, &file->line);
	if (!is_line_valid(tab, file))
		__exit(file, E_INVALID_LINE);
	set_duplicate_check(file);
	return ;
}
