/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:04 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/window_management.h"
#include "../../inc/rendering.h"
#include <math.h>

static float	degrees_to_radians(float degrees)
{
	return (degrees * (PI / 180.0f));
}

void	set_viewport(int32_t image_width, int32_t image_height,
	float (*viewport)[2], int hfov)
{
	float	theta;
	float	w;

	theta = degrees_to_radians((float)hfov);
	w = (float) tan(theta / 2);
	(*viewport)[U] = 2 * w;
	(*viewport)[V] = (*viewport)[U]
		* ((float)image_height / (float)image_width);
}
