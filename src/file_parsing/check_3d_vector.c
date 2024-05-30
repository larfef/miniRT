/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3d_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:54:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 12:31:17 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	check_3d_vector(char **p)
{
	float		tmp;
	int8_t		i;

	i = -1;
	while (++i != 3)
	{
		if (!is_length_valid(*p, 3))
			return (1);
		tmp = ft_atof(*p);
		if (tmp < 0 || tmp > 1)
			return (1);
		skip_float(p);
		if (i < 2 && **p != ',')
			return (1);
		if (i == 2 && **p != ' ')
			return (1);
		(*p)++;
	}
	return (0);
}
