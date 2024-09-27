/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:44:42 by gde-win          ###   ########.fr       */
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
