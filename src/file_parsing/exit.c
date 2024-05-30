/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:12:59 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:23:18 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "unistd.h"
#include "stdio.h"

void	__exit(t_file *file, char *error_message)
{
	close(file->fd);
	free(file->line_start);
	printf("miniRT: %s\n", error_message);
	exit(1);
}
