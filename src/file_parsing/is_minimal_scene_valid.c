/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minimal_scene_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:19:09 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:27:06 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_minimal_scene_valid(t_file *file)
{
	if (!file->minimal_scene[file->current_line])
		__exit(file, E_ELEM);
	return (true);
}
