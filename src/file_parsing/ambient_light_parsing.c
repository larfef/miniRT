/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light_parsing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:04:51 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 17:30:42 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	ambient_light_parsing(char *line)
{
	line++;
	skip_space(&line);
	if (!is_in_range(&line, 0))
		return (1);
	line += 3;
	if (!is_space(*line))
		return (1);
	skip_space(&line);
	if (!is_in_range(&line, 1))
		return (1);
	if (!is_end_of_line_valid(line))
		return (1);
	return (0);
}
