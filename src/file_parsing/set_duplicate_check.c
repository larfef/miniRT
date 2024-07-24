/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_duplicate_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:50:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:02:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

void	set_duplicate_check(t_file *file)
{
	file->minimal_scene[file->current_line] = true;
}
