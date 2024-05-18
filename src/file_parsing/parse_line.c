/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 17:29:11 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"

bool	parse_line(t_file *file_data)
{
	skip_space(&file_data->line);
	set_current_line_type(file_data);
	if (file_data->current_line == INVALID)
		return (1);
	if (file_data->current_line == NEWLINE)
		return (0);
	if (file_data->current_line == AMBIENT
		&& !ambient_light_parsing(file_data->line))
		return (0);
	return (1);
}