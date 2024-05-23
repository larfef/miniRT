/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:25:50 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 16:30:31 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool	error_message(char const *s, int errnum)
{
	if (s)
		printf("%s\n", s);
	else
		printf("miniRT: %s\n", strerror(errnum));
	return (1);
}
