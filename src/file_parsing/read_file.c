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
#include "../../inc/init_stack.h"
#include "../gnl/get_next_line.h"
#include "../libft/inc/libft.h"
#include <stdlib.h>

void	read_file(t_scene *scene, t_file *file, int option)
{
	while (1)
	{
		file->line_start = get_next_line(file->fd);
		if (!file->line_start
			&& errno == ENOMEM)
		{
			if (option == PARSE)
				__exit(file, strerror(ENOMEM));
			if (option == EXTRACT)
				___exit(file->line_start, (t_shapes *)scene->scene[_SHAPES]);//free and exit logic
		}
		else if (!file->line_start)
			return ;
		file->line = file->line_start;
		if (option == PARSE)
			parse_line(file);
		if (option == EXTRACT)
			extract_file_data(file, scene);
		free(file->line_start);
	}
}
