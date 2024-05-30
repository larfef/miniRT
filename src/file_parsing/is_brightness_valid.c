/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_brightness_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:13 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 12:30:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_brightness_valid(char *line)
{
	float	brightness;

	if (!is_length_valid(line, 3))
			return (1);
	brightness = ft_atof(line);
	if (brightness < 0 || brightness > 1)
		return (false);
	return (true);
}
