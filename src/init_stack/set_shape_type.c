/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shape_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:17:55 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Sets the shape type based on the character provided. This function
			assigns a specific shape type (e.g., _SPHERE, _CYLINDER, _PLANE)
			to the given type pointer depending on the input character.

	@param: c: The character that determines the shape type ('s' for sphere,
			   'c' for cylinder, 'p' for plane).
	@param: type: Pointer to the shape type variable that will be set
				  accordingly.
*/

void	set_shape_type(t_shape_type *type, char c)
{
	if (c == 's')
		*type = _SPHERE;
	else if (c == 'c')
		*type = _CYLINDER;
	else if (c == 'p')
		*type = _PLANE;
}
