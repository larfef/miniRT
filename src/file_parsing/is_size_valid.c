/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_size_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:38:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:15:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../../inc/init_stack.h"

bool	is_size_valid(char **line, t_scene *scene, int option)
{
	float		tmp;
	static int	i;

	if (option == PARSE && !is_length_valid(*line, LEN_MAX))
		return (false);
	tmp = ft_atof(*line);
	if (option == _SHAPES && i == HEIGHT)
		scene->shapes->size[HEIGHT] = tmp;
	else if (option == _SHAPES && i++ == DIAMETER)
		scene->shapes->size[DIAMETER] = tmp;
	if (option == PARSE
		&& tmp <= 0.0)
		return (false);
	return (true);
}
