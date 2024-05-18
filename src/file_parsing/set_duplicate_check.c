/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_duplicate_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:50:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 13:52:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_types.h"

void	set_duplicate_check(t_file *file_data)
{
	if (file_data->current_line == AMBIENT)
		file_data->is_ambient = true;
	if (file_data->current_line == CAMERA)
		file_data->is_camera = true;
	if (file_data->current_line == LIGHT)
		file_data->is_light = true;
}
