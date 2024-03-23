/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 22:05:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_rt.h"

int	open_file(char const *s)
{
	int32_t	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

bool	read_file(t_file *file, t_scene *scene)
{
	if (open_file(file->filename) < 0)
		return (1);
	file->line = get_next_line(file->fd);
	if (file->line)
		parse_line(file->line);
}