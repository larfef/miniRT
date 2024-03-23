/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:49:07 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 22:41:09 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static	bool	is_in_charset(char c, char const*charset)
{
	uint64_t	i;

	i = 0;
	while (charset[i]
		&& i < UINT64_MAX)
	{
		if (charset[i++] == c)
			return (1);
	}
	return (0);
}

uint64_t	ft_substr_len(char *s, char const *charset)
{
	uint64_t	i;

	i = 0;
	while (s[i]
		&& !is_in_charset(s[i], charset)
		&& i++ < SIZE_MAX);
	return (i);
}
