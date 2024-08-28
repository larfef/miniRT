/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_shape_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:49:12 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 09:51:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/types.h"

void	set_shape_type(t_shape_type *type, char c)
{
	if (c == 's')
		*type = _SPHERE;
	else if (c == 'c')
		*type = _CYLINDER;
	else if (c == 'p')
		*type = _PLANE;
}
