/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:46:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 09:49:36 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/init_stack.h"
#include "../libft/inc/libft.h"

void	init_stack(t_scene *scene)
{
	ft_memset(scene, '\0', sizeof(*scene));
	
}