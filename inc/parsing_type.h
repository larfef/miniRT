/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/17 19:04:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TYPE_H
# define PARSING_TYPE_H
typedef struct s_atod
{
	bool		is_fraction;
	char		sign;
	const char	*str
	double		fractional_part;
	double 		fraction_divisor;
	double 		integer_part;
	double		result;
}	t_atod;
#endif