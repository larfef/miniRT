/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minimal_scene_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:47:49 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_minimal_scene_valid(t_file *file)
{
	int	i;

	i = -1;
	while (++i != 3)
	{
		if (!file->minimal_scene[i])
			__exit(file, E_ELEM);
	}
	return (true);
}
