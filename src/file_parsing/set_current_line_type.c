/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:49:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 16:38:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing_types.h"

void	set_current_line_type(t_file *file_data)
{
	if (!ft_strncmp(file_data->line, "A", 1))
		file_data->current_line = AMBIENT;
	else if (!ft_strncmp(file_data->line, "C", 1))
		file_data->current_line = CAMERA;
	else if (!ft_strncmp(file_data->line, "L", 1))
		file_data->current_line = LIGHT;
	else if (!ft_strncmp(file_data->line, "cy", 2))
		file_data->current_line = CYLINDER;
	else if (!ft_strncmp(file_data->line, "pl", 2))
		file_data->current_line = PLANE;
	else if (!ft_strncmp(file_data->line, "sp", 2))
		file_data->current_line = SPHERE;
	else if (*file_data->line == '\n')
		file_data->current_line = NEWLINE;
	else
		file_data->current_line = INVALID;
}