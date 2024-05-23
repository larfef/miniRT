/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinates_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:33:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:28:02 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_coordinates_valid(char **p)
{
	int		i;

	i = -1;
	while (++i != 3)
	{
		if (!is_length_valid(*p, 15))
			return (false);
		skip_digit(p);
		if (i < 2 && **p != ',')
			return (false);
		if (i == 2 && **p != ' ')
			return (false);
		(*p)++;
	}
	return (true);
}
