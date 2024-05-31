/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:19:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:05:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_line_valid(int **tab, t_file *file)
{
	uint8_t	i;

	i = -1;
	while (tab[file->current_line][++i] != END
		&& file->parsing_functions[tab[file->current_line][i]](&file->line));
	if (tab[file->current_line][i] == END)
		return (true);
	return (false);
}
