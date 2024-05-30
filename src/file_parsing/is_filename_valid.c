/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:12:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:26:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"
#include "../libft/inc/libft.h"

void	is_filename_valid(char const *filename)
{
	char	*file_extension;

	file_extension = ft_strnstr(filename, ".rt", ft_strlen(filename));
	if (!file_extension
		|| ft_strlen(file_extension) != 3)
	{
		printf("miniRT: %s\n", E_EXT);
		exit(1);
	}
}
