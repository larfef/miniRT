/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:35:23 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:35:43 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "../../inc/types.h"

/*
	@dev:	Converts a string representing a floating-point number into its
			corresponding `float` value. Handles both integer and fractional
			parts, as well as optional leading spaces and signs ('+' or '-').
	@param:	str: a string containing the floating-point number to be converted.
	@return: the resulting float value corresponding to the input string.
*/

static void	move_ptr(t_atof *p)
{
	while (*(p->str) == ' ' || (*(p->str) > 8 && *(p->str) < 14))
		p->str++;
	if (*(p->str) == '+' || *(p->str) == '-')
	{
		if (*(p->str) == '-')
			p->sign = -1;
		p->str++;
	}
	while (*(p->str) == '0')
		p->str++;
}

static float	get_float(t_atof *p)
{
	move_ptr(p);
	while ((*(p->str) >= '0' && *(p->str) <= '9')
		|| (*(p->str) == '.' && !p->is_fraction))
	{
		if (*(p->str) == '.')
			p->is_fraction = true;
		else
		{
			if (p->is_fraction)
			{
				p->fractional_part = p->fractional_part * 10
					+ ((float)*(p->str) - '0');
				p->fraction_divisor *= 10;
			}
			else
				p->integer_part = p->integer_part * 10
					+ ((float)*(p->str) - '0');
		}
		p->str++;
	}
	p->result = p->integer_part + p->fractional_part / p->fraction_divisor;
	return (p->sign * p->result);
}

float	ft_atof(const char *str)
{
	t_atof	arg;

	memset((void *)&arg, 0, sizeof(arg));
	arg.fraction_divisor = 1.0f;
	arg.str = str;
	arg.sign = 1;
	return (get_float(&arg));
}
