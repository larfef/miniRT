/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:43:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:24:54 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parsing.h"

void	open_file(t_file *file)
{
	file->fd = open(file->file, O_RDONLY);
	if (file->fd < 0)
	{
		printf("miniRT: %s\n", strerror(errno));
		exit(1);
	}
}
