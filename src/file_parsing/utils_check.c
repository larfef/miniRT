/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 14:58:15 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_space(char c)
{
	if (c == 32
		|| (c >= 8 && c <= 12))
		return (true);
	return (false);
}

bool	is_end_of_line_valid(char *line)
{
	skip_space(&line);
	if (!(*line)
		|| *line == '\n')
		return (true);
	return (false);
}

bool	is_in_range(char **p, int type)
{
	double	tmp;
	//double
	if (type == 0)
	{
		tmp = ft_atod(*p);
		if (tmp >= 0.0 && tmp <= 1.0)
			return (true);
	}
	//int
	if (type == 1
		&& !is_rgb_valid(p))
		return (true);
	return (false);
}

bool	is_valid_character(char **p, char c, t_file *file_data)
{
	if (c == 'A' || c == 'L' || c == 'C')
	{
		if (c == 'A')
			file_data->is_ambient = true;
		if (c == 'C')
			file_data->is_camera = true;
		if (c == 'L')
			file_data->is_light = true;
		*p += 1;
		return (true);
	}
	if (!ft_strncmp(&c, "cy ", 3)
		|| !ft_strncmp(&c, "pl ", 3)
		|| !ft_strncmp(&c, "sp ", 3))
	{
		*p += 2;
		return (true);
	}
	return (false);
}
