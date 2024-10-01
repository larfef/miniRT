/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:13:11 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
	@dev:	Handles exiting the program due to an error, performing necessary
			cleanup before termination. Frees the given string and the linked
			list of shapes, prints the error message, and exits the program
			with an error code.

	@param: s:	Pointer to a string (typically a line or buffer) to be freed.
	@param: list: Pointer to the list of shapes to be freed.
*/

void	___exit(char *s, t_shapes *list)
{
	free(s);
	free_list(list);
	printf("miniRT: %s", strerror(errno));
	exit(1);
}
