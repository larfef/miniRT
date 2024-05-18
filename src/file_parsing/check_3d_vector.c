/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3d_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:54:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 18:04:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	check_3d_vector(char **p)
{
	double		tmp;
	int8_t		i;

	i = -1;
	while (++i != 3)
	{
		if (check_number_lenght(*p, 3))
			return (1);
		tmp = ft_atod(*p);
		if (tmp < 0 || tmp > 1)
			return (1);
		skip_double(p);
		if (i < 2 && **p != ',')
			return (1);
		if (i == 2 && **p != ' ')
			return (1);
		(*p)++;
	}
	return (0);
}
