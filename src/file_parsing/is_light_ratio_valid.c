/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light_ratio_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:45:58 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_light_ratio_valid(char **line, t_scene *scene, int option)
{
	float		tmp;

	tmp = ft_atof(*line);
	if (option == _AMBIENT)
		scene->ambient.light_ratio = tmp;
	if (option == PARSE)
		*line += 3;
	if (option == PARSE
		&& (tmp < 0.0 && tmp > 1.0))
		return (false);
	return (true);
}
