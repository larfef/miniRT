/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:40:38 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

/*
	@dev:	Initializes the `t_file` structure with the provided filename and
			sets up the instructions table. Clears the memory of the `file`
			structure, assigns the filename, and initializes the instruction
			table with predefined values.
	@param:	file: pointer to the `t_file` structure that will be initialized.
			The function clears its memory and assigns the `filename` and
			`instructions`.
	@param:	filename: the name of the file to be associated with the `t_file`
			structure. This is stored in the `file->file` member.
*/

void	init_file(t_file *file, char *filename)
{
	static int	*tab[6];

	ft_memset(file, '\0', sizeof(*file));
	file->file = filename;
	file->instructions = tab;
	init_instructions(file->instructions);
}
