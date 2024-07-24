/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"

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
