/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 23:23:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_rt.h"

int	open_file(char const *s)
{
	int32_t	fd;

	fd = open(s, O_RDONLY);
	return (fd);
}

static	void	skip_space(char **p)
{
	while (**p == 32
		|| (**p >= 8 && **p <= 12))
		(*p)++;
}

bool	read_file(t_file *file, t_scene *scene)
{
	if (open_file(file->filename) < 0)
		return (1);
	file->line = get_next_line(file->fd);
	if (file->line)
		parse_line(file->line);
}