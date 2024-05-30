/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:47:27 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 12:32:51 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"

void	skip_float(char **p)
{
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
	if (**p == '.')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
}

void	skip_digit(char **p)
{
	if (**p == '-')
		(*p)++;
	while (ft_isdigit(**p))
		(*p)++;
}

void	skip_space(char **p)
{
	while (**p == 32
		|| (**p >= 8 && **p <= 12 && **p != '\n'))
		(*p)++;
}
