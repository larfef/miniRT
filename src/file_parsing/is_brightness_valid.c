/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_brightness.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:21:13 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:27:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

bool	is_brightness_valid(char *line)
{
	double	brightness;

	if (!is_length_valid(*line, 3))
			return (1);
	brightness = ft_atod(line);
	if (brightness < 0 || brightness > 1)
		return (false);
	return (true);
}
