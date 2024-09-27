/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:51:46 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/types.h"

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
