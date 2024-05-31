/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:49:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 09:51:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing_types.h"

void	set_current_line_type(t_file *file)
{
	if (!ft_strncmp(file->line, "A", 1))
		file->current_line = AMBIENT;
	else if (!ft_strncmp(file->line, "C", 1))
		file->current_line = CAMERA;
	else if (!ft_strncmp(file->line, "L", 1))
		file->current_line = LIGHT;
	else if (!ft_strncmp(file->line, "cy", 2))
		file->current_line = CYLINDER;
	else if (!ft_strncmp(file->line, "pl", 2))
		file->current_line = PLANE;
	else if (!ft_strncmp(file->line, "sp", 2))
		file->current_line = SPHERE;
	else if (*file->line == '\n')
		file->current_line = NEWLINE;
	else
		file->current_line = INVALID;
}