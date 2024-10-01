/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_element_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:16:36 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

/*
	@dev:	Sets the element type based on the character provided. Depending
			on the input character, the function assigns the corresponding
			element type, such as _AMBIENT, _CAMERA, _LIGHT, or _SHAPES, to
			the given element_type pointer.

	@param: c: The character used to determine the element type (e.g., 'A',
			   'C', 'L').
	@param: element_type: Pointer to the element type to be set.
*/

void	set_element_type(char c, t_elements_types *element_type)
{
	if (c == 'A')
		*element_type = _AMBIENT;
	else if (c == 'C')
		*element_type = _CAMERA;
	else if (c == 'L')
		*element_type = _LIGHT;
	else
		*element_type = _SHAPES;
}
