/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:01:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 14:40:41 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

//bool	is_rgb_valid(char **p)
//{
//	int	i;
//	int	tmp;
//
//	i = -1;
//	while (++i != 3)
//	{
//		tmp = ft_atoi(*p);
//		if (tmp < 0 || tmp > 255)
//			return (false);
//		skip_digit(p);
//		if (i < 2 && **p != ',')
//			return (false);
//		(*p)++;
//	}
//	return (true);
//}

bool	is_rgb_valid(char **p, t_scene *scene, int option)
{
	int			i;
	int			tmp;

	i = -1;
	while (++i != 3)
	{
		tmp = ft_atoi(*p);
		if (option == _SHAPES)
			scene->shapes->color.color |= (tmp & 0xFF) << (8 * (3 - i));
		if (option == _AMBIENT)
			scene->ambient.color.color |= (tmp & 0xFF) << (8 * (3 - i));
		if (option == PARSE
			&& (tmp < 0 || tmp > 255))
			return (false);
		skip_digit(p, NULL, 0);
		if (option == PARSE
			&& i < 2 && **p != ',')
			return (false);
		(*p)++;
	}
	return (true);
}
