/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:08:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 12:32:13 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	sphere_parsing(char *line)
{
	line += 2;
	skip_space(&line);
	if (!is_coordinates_valid(&line))
		return (1);
	skip_space(&line);
	if (!is_length_valid(line, LEN_MAX))
		return (false);
	skip_float(&line);
	skip_space(&line);
	if (!ft_isdigit(*line))
		return (1);
	if (!is_rgb_valid(&line))
		return (1);
	skip_space(&line);
	if (!is_end_of_line_valid(line))
		return (1);
	return (0);
}
