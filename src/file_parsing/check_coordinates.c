/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:33:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 17:51:16 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	check_coordinates(char **p)
{
	int	i;
	double	tmp;

	i = -1;
	while (++i != 3)
	{
		if (check_number_lenght(*p, 15))
			return (1);
		skip_digit(p);
		if (i < 2 && **p != ',')
			return (1);
		if (i == 2 && **p != ' ')
			return (1);
		(*p)++;
	}
	return (0);
}
