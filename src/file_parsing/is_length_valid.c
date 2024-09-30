/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_length_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:45:03 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

/*
	@dev:	Checks whether the length of a given numeric string (potentially
			including a decimal point and negative sign) is within a specified
			maximum length. This is used to ensure that the numeric string
			does not exceed a reasonable size for parsing or validation.

	@param:	s: A pointer to the string representing the numeric value that
			needs to be checked.
	@param:	length_max: The maximum allowed length of the numeric string
			(including digits before and after the decimal point).

	@behavior:
		1. Initializes a counter (`tmp`) to track the length of the numeric
		   string.
		2. If the string starts with a negative sign (`'-'`), it skips it.
		3. Counts the digits before the decimal point (if present), ensuring
		   the count does not exceed `INT8_MAX`.
		4. If a decimal point (`'.'`) is encountered, it skips over it and
		   continues counting digits after the decimal point.
		5. Compares the total length (`tmp`) against the specified `length_max`.
		6. Returns `false` if the length exceeds `length_max`, and `true` if
		   it is within the valid range.

	@return:	Returns `true` if the length of the numeric string is within
				the specified limit, or `false` if it exceeds the limit.
*/

bool	is_length_valid(char *s, int8_t length_max)
{
	int8_t	tmp;

	tmp = 0;
	if (*s == '-')
		s++;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (*s == '.')
		s++;
	while (ft_isdigit(*s)
		&& ++tmp < INT8_MAX)
		s++;
	if (tmp > length_max)
		return (false);
	return (true);
}
