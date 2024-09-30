/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minimal_scene_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:47:49 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*
	@dev:	Checks if the minimal scene requirements are satisfied by ensuring
			that the essential elements of the scene (ambient light, camera,
			and light) are present. If any of these elements are missing,
			the function exits the program with an error.

	@param:	file: A pointer to the `t_file` structure, which contains the
			`minimal_scene` array, representing the presence or absence of
			the required scene elements. The array should have 3 elements,
			where each index corresponds to one of the mandatory components
			(ambient light, camera, and light).

	@behavior:
		1. Iterates through the `minimal_scene` array, which has 3 elements
		   corresponding to the required scene components:
		   - Index 0: Ambient light.
		   - Index 1: Camera.
		   - Index 2: Light.
		2. If any of these elements are missing (`file->minimal_scene[i] == 0`),
		   the function immediately calls `__exit()` with an error message
		   (`E_ELEM`), terminating the program.
		3. If all three elements are present, the function returns `true`,
		   indicating that the minimal scene requirements are satisfied.

	@return:	Returns `true` if all required elements (ambient light, camera,
				and light) are present; exits the program if any are missing.
*/

bool	is_minimal_scene_valid(t_file *file)
{
	int	i;

	i = -1;
	while (++i != 3)
	{
		if (!file->minimal_scene[i])
			__exit(file, E_ELEM);
	}
	return (true);
}
