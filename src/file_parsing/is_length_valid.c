/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_length_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:45:03 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_length_valid(char *s, int8_t length_max)
{
	int8_t	tmp;

	tmp = 0;
	if (*s == '-')
		s++;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (tmp > length_max)
		return (false);
	return (true);
}
