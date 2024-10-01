/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/01 13:15:08 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/types.h"
#include <stdlib.h>

/*
	@dev:	Releases all the memory allocated for the linked list of shapes.
			It iterates through the list of shapes, freeing each node
			and moving to the next node until the entire list is deallocated.

	@param: list: Pointer to the head of the shapes list to be freed.
*/

void	free_list(t_shapes *list)
{
	t_shapes	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}
