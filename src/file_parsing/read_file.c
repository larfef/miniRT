/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:51:27 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../gnl/get_next_line.h"
#include "../libft/inc/libft.h"
#include <stdlib.h>

/*
	@dev: Reads lines from a file specified in the `t_file` structure
			and processes each line based on the specified option. The
			function can either parse the line or extract data from it.
			Memory management is handled to ensure that resources are
			freed appropriately.

	@param:	scene: A pointer to the `t_scene` structure, which
			contains data about the scene being processed. This
			structure is updated during the extraction of data.

	@param:	file: A pointer to the `t_file` structure, which
			contains information about the file, including its
			file descriptor and the current line being read.

	@param:	option: An integer that specifies the operation mode.
			Possible values include `PARSE` for parsing lines and
			`EXTRACT` for extracting data from lines.

	@behavior:
		1. Enters an infinite loop to continuously read lines from
		   the file until no more lines are available.
		2. Calls `get_next_line` to read the next line from the file
		   descriptor.
		3. If `get_next_line` fails due to memory allocation issues
		   (ENOMEM) and the operation mode is PARSE, it exits the
		   program with an error message.
		4. If the operation mode is EXTRACT, it exits using a different
		   exit function that manages extraction failures.
		5. If no line is read, the function returns, ending the loop.
		6. Sets the `line` member of the `t_file` structure to the
		   read line and processes it based on the specified option.
		7. For PARSE, it calls `parse_line` to process the current
		   line.
		8. For EXTRACT, it calls `extract_file_data` to extract
		   relevant information from the line.
		9. Frees the memory allocated for the current line before
		   reading the next line.

	@return: None. The function may terminate the program if an
			 error occurs during file reading or processing.
*/

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
				___exit(file->line_start, scene->shapes);
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
