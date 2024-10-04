/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:08:38 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:14:57 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../libft/inc/libft.h"
#include "../../inc/constant.h"

/*
	@dev:	Parses the current line from the file, extracting scene elements
			and shape data. Depending on the element type, it updates the
			scene structure accordingly. If the element is a shape, it
			adds it to the shape list. Parsing functions are executed
			according to the instruction set for each line type.

	@param: file: Pointer to the file structure, which holds the current line
				  and parsing instructions.
	@param: scene: Pointer to the scene structure, which is updated with the
				   extracted data from the file.
*/

static bool	list_add_front(t_shapes **list)
{
	t_shapes	*node;

	node = ft_calloc(1, sizeof(*node));
	if (!node)
		return (1);
	node->next = *list;
	*list = node;
	return (0);
}

void	extract_file_data(t_file *file, t_scene *scene)
{
	uint8_t				i;

	skip_space(&file->line, NULL, 0);
	if (*file->line == '\n')
		return ;
	set_element_type(*(file->line), &scene->element_type);
	set_current_line_type(file);
	if (scene->element_type == _SHAPES)
	{
		if (list_add_front(&scene->shapes))
			___exit(file->line_start, scene->shapes);
		set_shape_type(&(scene->shapes->type), *(file->line));
	}
	skip_line_start((int)scene->element_type, &file->line);
	i = -1;
	while (file->instructions[file->current_line][++i] != EOL
			&& file->parsing_functions[file->instructions
				[file->current_line][i]](&file->line, scene,
					scene->element_type));
}
