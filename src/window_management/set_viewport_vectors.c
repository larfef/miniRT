/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewport_vectors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 21:24:46 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "../../inc/window_management.h"
#include "../../inc/operation.h"

void	set_viewport_vectors(float (*viewport)[2],
	t_vector (*viewport_vectors)[2], t_vector *w)
{
	t_vector	vup;
	t_vector	u;
	t_vector	minus_v;

	ft_memset(&u, 0, sizeof(u));
	vup = get_vup(w);
	u = cross_product(vup, *w);
	normalize(&u);
	minus_v = cross_product(*w, u);
	minus_v = multiply_vector(minus_v, -1);
	normalize(&minus_v);
	(*viewport_vectors)[U] = multiply_vector(u, (*viewport)[WIDTH]);
	(*viewport_vectors)[V] = multiply_vector(minus_v, (*viewport)[HEIGHT]);
}
