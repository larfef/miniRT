/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 14:58:24 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_duplicate(t_file *file)
{
	if (file->current_line == AMBIENT
		&& file->is_ambient)
		return (true);
	if (file->current_line == CAMERA
		&& file->is_camera)
		return (true);
	if (file->current_line == LIGHT
		&& file->is_light)
		return (true);
	return (false);
}
