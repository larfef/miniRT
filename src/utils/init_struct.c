/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:28:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/10/02 21:28:32 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../../inc/types.h"

void	init_struct(t_window *win, t_ray_tracing *rt, t_file *file)
{
	ft_memset(win, 0, sizeof(*win));
	ft_memset(rt, 0, sizeof(*rt));
	ft_memset(file, 0, sizeof(*file));
}
