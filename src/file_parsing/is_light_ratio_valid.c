/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_light_ratio_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 08:38:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:15:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_light_ratio_valid(char **line)
{
	float	tmp;

	tmp = ft_atof(*line);
	*line += 3;
	if (tmp >= 0.0 && tmp <= 1.0)
		return (true);
	return (false);
}