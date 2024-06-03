/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinates_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:33:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 12:31:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_coordinates_valid(char **p)
{
	int		i;

	i = -1;
	while (++i != 3)
	{
		if (!is_length_valid(*p, 15))
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

//bool	is_coordinates_valid(char **p, void *ptr, int option)
//{
//	float		tmp;
//	int			i;
//	t_shapes	*shape;
//
//	i = -1;
//	if (option == EXTRACT)
//		shape = (t_shapes *)ptr;
//	while (++i != 3)
//	{
//		if (option == EXTRACT)
//		{
//			tmp = ft_atof(*p);
//			shape->center[i] = tmp;
//		}
//		if (option == PARSE
//			&& !is_length_valid(*p, 15))
//			return (false);
//		skip_float(p);
//		if (option == PARSE
//			&& i < 2 && **p != ',')
//			return (false);
//		(*p)++;
//	}
//	return (true);
//}