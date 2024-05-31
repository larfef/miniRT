/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:35:09 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_space(char **p)
{
	if (**p == 32
		|| (**p >= 8 && **p <= 12))
		return (true);
	return (false);
}

bool	is_end_of_line_valid(char **line)
{
	skip_space(line);
	if (!(**line)
		|| **line == '\n')
		return (true);
	return (false);
}

bool	is_fov_valid(char **p)
{
	int	tmp;

	tmp = ft_atoi(*p);
	if (tmp < 0 || tmp > 180)
		return (false);
	return (true);
}

bool	is_digit(char **p)
{
	if (**p >= '0' && **p <= '9')
		return (true);
	return (false);
}
