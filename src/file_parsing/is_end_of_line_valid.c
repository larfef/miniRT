/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_end_of_line_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:41:23 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:49:30 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_end_of_line_valid(char **line)
{
	if (!(**line)
		|| **line == '\n')
		return (true);
	return (false);
}

//bool	is_end_of_line_valid(char **line, void *ptr, int option)
//{
//	if (!(**line)
//		|| **line == '\n')
//		return (true);
//	return (false);
//}