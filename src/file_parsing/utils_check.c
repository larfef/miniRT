/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:52:27 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

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
