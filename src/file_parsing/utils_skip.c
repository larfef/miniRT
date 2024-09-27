/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:52:52 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

void	skip_line_start(int type, char **p)
{
	if (type <= 2)
		(*p)++;
	else
		*p += 3;
}

bool	skip_float(char **p, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	if (!is_length_valid(*p, LEN_MAX))
		return (0);
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	if (**p == '.')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	return (1);
}

bool	skip_digit(char **p, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	return (1);
}

bool	skip_space(char **p, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	while (**p == 32
		|| (**p >= 8 && **p <= 12 && **p != '\n'))
		(*p)++;
	return (1);
}
