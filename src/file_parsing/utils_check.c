/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

//bool	is_fov_valid(char **p)
//{
//	int	tmp;
//
//	tmp = ft_atoi(*p);
//	if (tmp < 0 || tmp > 180)
//		return (false);
//	return (true);
//}
//
//bool	is_digit(char **p)
//{
//	if (**p >= '0' && **p <= '9')
//		return (true);
//	return (false);
//}

bool	is_fov_valid(char **p, t_scene *scene, int option)
{
	int	tmp;

	(void)scene;
	(void)option;
	tmp = ft_atoi(*p);
	if (option == PARSE
		&& (tmp < 0 || tmp > 180))
		return (false);
	if (option == _CAMERA)
		scene->camera.fov = tmp;
	return (true);
}

bool	is_digit(char **p, t_scene *scene, int option)
{
	(void)scene;
	(void)option;
	if (**p >= '0' && **p <= '9')
		return (true);
	return (false);
}

void	set_float(float value, float *destination)
{
	*destination = value;
}
