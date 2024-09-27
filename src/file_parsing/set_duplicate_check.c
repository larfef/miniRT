/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_duplicate_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:52:09 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

void	set_duplicate_check(t_file *file)
{
	file->minimal_scene[file->current_line] = true;
}
