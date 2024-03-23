/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 23:09:44 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/23 23:27:22 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mini_rt.h"

bool	check_type_identifier(char *id, bool *is_dup, t_file *file)
{
	int32_t		ret;
	uint64_t	len;

	len = ft_substr_len(file->line, WHITESPACE);
	if (len > 2)
		return (1);
	ret = ft_strncmp(file->line, id, len);
	if (ret
		|| (!ret
		&& *is_dup))
		return (1);
	else if (!ret)
		*is_dup = true;
	return (0);
}
