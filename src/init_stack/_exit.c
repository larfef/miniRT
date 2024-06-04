/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 17:22:38 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init_stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	___exit(char *s, t_shapes *list)
{
	free(s);
	free_list(list);
	printf("miniRT: %s", strerror(errno));
	exit(1);
}
