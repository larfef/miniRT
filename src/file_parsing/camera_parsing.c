/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:31:20 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:17:59 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

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
	//line++ can be made during the function call
	line++;
	skip_space(&line);
	if (!is_coordinates_valid(&line))
		return (1);
	skip_space(&line);
	if (check_3d_vector(&line))
		return (1);
	skip_space(&line);
	if (!ft_isdigit(*line))
		return (1);
	if (check_fov(&line))
		return (1);
	skip_digit(&line);
	if (!is_end_of_line_valid(line))
		return (1);
	return (0);
}