/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_lenght.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:42:48 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:26:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_lenght_valid(char *s, int8_t lenght_max)
{
	int8_t	tmp;

	tmp = 0;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (tmp > lenght_max)
		return (1);
	return (0);
}
