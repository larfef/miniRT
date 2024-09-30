/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:49:08 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_rgb_valid(char **p, t_scene *scene, int option)
{
	int			i;
	int			tmp;

	i = -1;
	while (++i != 3)
	{
		tmp = ft_atoi(*p);
		if (option == _SHAPES)
			scene->shapes->color.color |= (tmp & 0xFF) << (8 * (2 - i));
		if (option == _AMBIENT)
			scene->ambient.color.color |= (tmp & 0xFF) << (8 * (2 - i));
		if (option == PARSE
			&& (tmp < 0 || tmp > 255))
			return (false);
		skip_digit(p, NULL, 0);
		if (option == PARSE
			&& i < 2 && **p != ',')
			return (false);
		if (**p != '\0')
			(*p)++;
	}
	return (true);
}
