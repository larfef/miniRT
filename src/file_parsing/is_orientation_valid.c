/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_orientation_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:48:33 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_orientation_valid(char **p, t_scene *scene, int option)
{
	float		tmp;
	int8_t		i;

	i = -1;
	while (++i != 3)
	{
		if (option == PARSE
			&& !is_length_valid(*p, 3))
			return (false);
		tmp = ft_atof(*p);
		if (option == _CAMERA)
			set_float(tmp, (float *)&scene->camera.orientation.dir + i);
		if (option == _SHAPES
			&& scene->shapes->type != _SPHERE)
			set_float(tmp, (float *)&scene->shapes->orientation.dir + i);
		if (option == PARSE
			&& (tmp < -1 || tmp > 1))
			return (false);
		skip_float(p, NULL, 0);
		if (option == PARSE
			&& (i < 2 && **p != ','))
			return (false);
		(*p)++;
	}
	return (true);
}
