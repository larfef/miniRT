/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:11:35 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/01 13:11:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../../inc/types.h"
#include "../inc/key_codes.h"
#include "../../inc/init_stack.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

int	k_input(int key, t_hook *ptr)
{
	if (key == ESCAPE)
	{
		mlx_clear_window(ptr->mlx, ptr->window);
		free_list(ptr->shapes);
		exit(0);
	}
	return (0);
}
