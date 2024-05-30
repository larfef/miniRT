/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:09:20 by rkersten         ###   ########.fr       */
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
	float	tmp;
	//double
	if (type == 0)
	{
		tmp = ft_atof(*p);
		if (tmp >= 0.0 && tmp <= 1.0)
			return (true);
	}
	//int
	if (type == 1
		&& !is_rgb_valid(p))
		return (false);
	return (true);
}
