/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light_ratio_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:38:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:15:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"
#include "../../inc/init_stack.h"

//bool	is_light_ratio_valid(char **line)
//{
//	float	tmp;
//
//	tmp = ft_atof(*line);
//	*line += 3;
//	if (tmp >= 0.0 && tmp <= 1.0)
//		return (true);
//	return (false);
//}

bool	is_light_ratio_valid(char **line, void *ptr, int option)
{
	float		tmp;
	t_ambient	*ambient;

	tmp = ft_atof(*line);
	if (option == EXTRACT)
	{
		ambient = (t_ambient *)ptr;
		ambient->light_ratio = tmp;
	}
	if (option == PARSE)
		*line += 3;
	if (option == PARSE &&
		(tmp >= 0.0 && tmp <= 1.0))
		return (true);
	return (false);
}
