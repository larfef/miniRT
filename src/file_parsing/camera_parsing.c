/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:31:20 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 18:11:45 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

static bool	check_fov(char **p)
{
	int	tmp;

	tmp = ft_atoi(*p);
	if (tmp < 0 || tmp > 180)
		return (1);
	return (0);
}

bool	camera_parsing(char *line)
{
	line++;
	skip_space(&line);
	if (!is_coordinates_valid(&line))
		return (1);
	skip_space(&line);
	if (check_3d_vector(&line))
		return (1);
	skip_space(&line);
	if (!ft_is_digit(&line))
		return (1);
	if (check_fov(&line))
		return (1);
	skip_digit(&line);
	if (!is_end_of_line_valid(&line))
		return (1);
	return (0);
}