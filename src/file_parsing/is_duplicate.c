/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:22 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:24:37 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_duplicate(t_file *file)
{
	if (file->current_line < 3 && file->minimal_scene[file->current_line])
		__exit(file, E_DUP);		
	return (false);
}
