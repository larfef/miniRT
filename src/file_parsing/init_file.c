/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:46:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 09:49:36 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

void	init_file(t_file *file, char *filename)
{
	static int	*tab[6];

	ft_memset(file, '\0', sizeof(file));
	file->file = filename;
	file->instructions = tab;
	init_instructions(file->instructions);
}
