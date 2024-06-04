/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3d_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:54:36 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 14:22:48 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

//bool	is_orientation_valid(char **p)
//{
//	float		tmp;
//	int8_t		i;
//
//	i = -1;
//	while (++i != 3)
//	{
//		if (!is_length_valid(*p, 3))
//			return (false);
//		tmp = ft_atof(*p);
//		if (tmp < 0 || tmp > 1)
//			return (false);
//		skip_float(p);
//		if (i < 2 && **p != ',')
//			return (false);
//		if (i == 2 && **p != ' ')
//			return (false);
//		(*p)++;
//	}
//	return (true);
//}

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
			scene->camera.orientation[i] = tmp;
		if (option == _SHAPES
			&& scene->shapes->type != _SPHERE)
			scene->shapes->orientation[i] = tmp;
		if (option == PARSE
			&& (tmp < 0 || tmp > 1))
			return (false);
		skip_float(p, NULL, 0);
		if (option == PARSE
			&& (i < 2 && **p != ','))
			return (false);
		(*p)++;
	}
	return (true);
}
