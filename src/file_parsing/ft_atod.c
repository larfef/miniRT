/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:42:18 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/18 17:26:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdint.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../../inc/parsing.h"

static void	move_ptr(t_atod *p)
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

static double	get_double(t_atod *p)
{
	move_ptr(p);
    while ((*(p->str) >= '0' && *(p->str) <= '9') || (*(p->str) == '.' && !p->is_fraction))
    {
        if (*(p->str) == '.')
            p->is_fraction = true;
        else
        {
            if (p->is_fraction)
            {
                p->fractional_part = p->fractional_part * 10 + (*(p->str) - '0');
                p->fraction_divisor *= 10;
            }
            else
                p->integer_part = p->integer_part * 10 + (*(p->str) - '0');
        }
        p->str++;
    }
    p->result = p->integer_part + p->fractional_part / p->fraction_divisor;
    return p->sign * p->result;
}

double	ft_atod(const char *str)
{
    t_atod  arg;

    ft_memset((void *)&arg, '\0', sizeof(arg));
    arg.fraction_divisor = 1;
	arg.str = str;
    arg.sign = 1;
    return (get_double(&arg));
}
