/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:40:16 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "unistd.h"
#include "stdio.h"

/*
	@dev:	Handles an error by closing the file descriptor, freeing allocated
			memory, displaying an error message, and terminating the program
			with a non-zero exit code.
	@param:	file: pointer to a file structure, which contains the file descriptor
			and a pointer to dynamically allocated memory for reading
			lines. These resources are cleaned up before exiting.
	@param:	error_message: a string containing the error message to be displayed
			to the user, which is printed to the console.
*/

void	__exit(t_file *file, char *error_message)
{
	close(file->fd);
	free(file->line_start);
	printf("miniRT: %s\n", error_message);
	exit(1);
}
