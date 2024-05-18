/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:43:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 15:29:40 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>
#include "../../inc/parsing_types.h"

void	open_file(t_file *file)
{
	file->fd = open(file->file_path, O_RDONLY);
	if (file->fd < 0)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
}