/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minimal_scene_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:19:09 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 08:25:42 by rkersten         ###   ########.fr       */
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
