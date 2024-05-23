/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 15:36:15 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"

bool	parse_line(t_file *file)
{
	skip_space(&file->line);
	set_current_line_type(file);
	if (file->current_line == NEWLINE)
		return (0);
	if (file->current_line == INVALID)
		return (1);
	if (is_duplicate(file))
		return (1);
	if (file->current_line == AMBIENT
		&& ambient_light_parsing(file->line))
		return (1);
	if (file->current_line == CAMERA
		&& camera_parsing(file->line))
		return(1);
	if (file->current_line == LIGHT
		&& light_parsing(file->line))
		return(1);
	if (file->current_line == SPHERE
		&& sphere_parsing(file->line))
		return(1);
	if (file->current_line == PLANE
		&& plane_parsing(file->line))
		return (1);
	if (file->current_line == CYLINDER
		&& cylinder_parsing(file->line))
		return (1);
	set_duplicate_check(file);
	return (0);
}
