/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:44:22 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "../libft/inc/libft.h"
#include "../../inc/constant.h"
#include <stdio.h>

/*
	@dev:	Validates the input file by opening it, reading its contents,
			and ensuring that the file adheres to the minimum scene
			requirements for the ray tracing application. If the file is valid,
			a confirmation message is printed and the file descriptor is closed.

	@param:	file: A pointer to the `t_file` structure, which contains
			information about the file, including its file descriptor and
			other relevant metadata for parsing and validation.

	@behavior:
		1. Calls `open_file()` to open the file specified in the `file`
		   structure.
		2. Reads and parses the file contents using `read_file()` in PARSE mode.
		3. Ensures that the file contains the minimal scene data by calling
		   `is_minimal_scene_valid()`.
		4. If the file is valid, prints "miniRT: Valid file" to the console.
		5. Closes the file descriptor.

	@return:	None. The function prints a validation message if the file is
				valid or terminates if an error is encountered during validation.
*/

void	is_file_valid(t_file *file)
{
	open_file(file);
	read_file(NULL, file, PARSE);
	is_minimal_scene_valid(file);
	printf("miniRT: Valid file\n");
	close(file->fd);
}
