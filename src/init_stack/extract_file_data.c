/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"
#include "../libft/inc/libft.h"

static bool	list_add_front(t_shapes **list)
{
	t_shapes *node;

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
		   && file->parsing_functions[file->instructions[file->current_line][i]](&file->line, scene, scene->element_type));
	return ;
}
