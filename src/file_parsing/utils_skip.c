/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:47:27 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:43:07 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

bool	skip_float(char **p)
{
	if (!is_length_valid(*p, LEN_MAX))
		return (0);
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	if (**p == '.')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	return (1);
}

bool	skip_digit(char **p)
{
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	return (1);
}

bool	skip_space(char **p)
{
	while (**p == 32
		|| (**p >= 8 && **p <= 12 && **p != '\n'))
		(*p)++;
	return (1);
}

void	skip_line_start(t_element_type type, char **p)
{
	if (type <= 2)
		(*p)++;
	else 
		*p += 3;
}

//bool	skip_float(char **p, void *ptr, int option)
//{
//	if (!is_length_valid(*p, LEN_MAX))
//		return (0);
//	if (**p == '-')
//		(*p)++;
//	while (ft_isdigit(**p))
//		(*p)++;
//	if (**p == '.')
//		(*p)++;
//	while (ft_isdigit(**p))
//		(*p)++;
//	return (1);
//}
//
//bool	skip_digit(char **p, void *ptr, int option)
//{
//	if (**p == '-')
//		(*p)++;
//	while (ft_isdigit(**p))
//		(*p)++;
//	return (1);
//}
//
//bool	skip_space(char **p, void *ptr, int option)
//{
//	while (**p == 32
//		   || (**p >= 8 && **p <= 12 && **p != '\n'))
//		(*p)++;
//	return (1);
//}