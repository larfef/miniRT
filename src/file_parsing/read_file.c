/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 16:29:59 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../gnl/get_next_line.h"
#include <stdlib.h>

void	read_file(t_file *file)
{
	char	*tmp;

	open_file(file);
	while (1)
	{
		tmp = get_next_line(file->fd);
		file->line = tmp;
		if (!file->line)
			return ;
		if (parse_line(file))
		{
			free(tmp);
			return ;
		}
		free(tmp);
	}
}
