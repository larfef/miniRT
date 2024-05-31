/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../gnl/get_next_line.h"
#include <stdlib.h>

void	read_file(t_file *file)
{
	while (1)
	{
		file->line_start = get_next_line(file->fd);
		file->line = file->line_start;
		if (!file->line_start)
			if (errno == ENOMEM)
				__exit(file, strerror(ENOMEM));
		if (!file->line_start)
			return ;
		parse_line(file);
		free(file->line_start);
	}
}
