/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:50:37 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

/*
	@dev:	Attempts to open a file specified in the `t_file`
			structure for reading. If the file fails to open,
			it prints an error message indicating the reason
			for the failure and terminates the program.

	@param:	file:	A pointer to the `t_file` structure that
					contains the filename and file descriptor.
					This structure is modified to store the
					file descriptor of the opened file.

	@behavior:
		1. Uses the `open()` system call to open the file in
		   read-only mode.
		2. Checks if the file descriptor is less than 0,
		   indicating an error occurred during opening.
		3. If an error occurs, it prints the corresponding
		   error message using `strerror(errno)` and exits
		   the program with a failure status.

	@return:	None. The function terminates the program if
				an error occurs.
*/

void	open_file(t_file *file)
{
	file->fd = open(file->file, O_RDONLY);
	if (file->fd < 0)
	{
		printf("miniRT: %s\n", strerror(errno));
		exit(1);
	}
}
