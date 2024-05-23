/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 16:25:44 by rkersten         ###   ########.fr       */
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
			if (errno == ENOMEM)
				exit(error_message(NULL, ENOMEM));
		if (!file->line) // add check if mandatory elements are present before eof
			return ;
		if (parse_line(file))
		{
			free(tmp);
			exit(error_message(NULL, file->errnum));
		}
		free(tmp);
	}
}
