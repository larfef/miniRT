/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:24 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:41:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	is_fov_valid(char **p)
{
	int	tmp;

	tmp = ft_atoi(*p);
	if (tmp < 0 || tmp > 180)
		return (false);
	return (true);
}

bool	is_digit(char **p)
{
	if (**p >= '0' && **p <= '9')
		return (true);
	return (false);
}

//bool	is_fov_valid(char **p, void *ptr, int option)
//{
//	int	tmp;
//
//	tmp = ft_atoi(*p);
//	if (tmp < 0 || tmp > 180)
//		return (false);
//	return (true);
//}
//
//bool	is_digit(char **p, void *ptr, int option)
//{
//	if (**p >= '0' && **p <= '9')
//		return (true);
//	return (false);
//}
