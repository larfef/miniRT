/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_size_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:50:17 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_size_valid(char **line, t_scene *scene, int option)
{
	float		tmp;
	static int	i;

	if (option == PARSE && !is_length_valid(*line, LEN_MAX))
		return (false);
	tmp = ft_atof(*line);
	if (option == PARSE
		&& tmp <= 0.0)
		return (false);
	if (option == _SHAPES && scene->shapes->type != _PLANE)
	{
		if (i == HEIGHT)
		{
			scene->shapes->size[HEIGHT] = tmp;
			i = DIAMETER;
		}
		else if (i == DIAMETER)
		{
			scene->shapes->size[DIAMETER] = tmp;
			if (scene->shapes->type == _CYLINDER)
				i = HEIGHT;
		}
	}
	return (true);
}
