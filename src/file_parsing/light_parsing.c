/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:16:57 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:19:56 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	light_parsing(char *line)
{
	line++;
		skip_space(&line);
	if (!is_coordinates_valid(&line))
		return (1);
	skip_space(&line);
	if (!ft_isdigit(*line))
		return (1);
	if (check_brightness(&line))
		return(1);
	skip_digit(&line);
	if (!is_end_of_line_valid(line))
		return (1);
	return (0);
}