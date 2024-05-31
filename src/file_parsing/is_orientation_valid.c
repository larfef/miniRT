/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3d_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:54:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:22:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_orientation_valid(char **p)
{
	float		tmp;
	int8_t		i;

	i = -1;
	while (++i != 3)
	{
		if (!is_length_valid(*p, 3))
			return (false);
		tmp = ft_atof(*p);
		if (tmp < 0 || tmp > 1)
			return (false);
		skip_float(p);
		if (i < 2 && **p != ',')
			return (false);
		if (i == 2 && **p != ' ')
			return (false);
		(*p)++;
	}
	return (true);
}
