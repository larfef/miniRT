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

// bool	is_line_valid(int **tab, t_file *file)
// {
// 	uint8_t	i;
//
// 	i = -1;
// 	while (tab[file->current_line][++i] != END
// 		&& file->parsing_functions[tab[file->current_line][i]]
// 			(&file->line, NULL, PARSE));
// 	if (tab[file->current_line][i] == END)
// 		return (true);
// 	return (false);
// }

bool	is_line_valid(int **tab, t_file *file)
{
	uint8_t	i;

	i = 0;
	while (tab[file->current_line][i] != END
		&& file->parsing_functions[tab[file->current_line][i]](&file->line, NULL, PARSE))
	{
		i++;
	}
	if (tab[file->current_line][i] == END)
		return (true);
	return (false);
}