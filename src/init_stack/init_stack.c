/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:15:57 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init_stack.h"
#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"
#include "../../inc/constant.h"

/*
	@dev:	Initializes the scene data structure and sets up the file for
			parsing. It clears the memory for the scene, initializes function
			pointers, opens the specified file, and reads its contents to
			extract the scene data.

	@param: scene: Pointer to the scene structure to be initialized.
	@param: file:  Pointer to the file structure containing the file
				  information to be opened and parsed.
*/

void	init_stack(t_scene *scene, t_file *file)
{
	ft_memset(scene, '\0', sizeof(*scene));
	init_fct_ptr(scene);
	open_file(file);
	read_file(scene, file, EXTRACT);
}
