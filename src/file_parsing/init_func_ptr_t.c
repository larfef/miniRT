/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func_ptr_t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:43:25 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:02:06 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

void	init_func_ptr_t(t_file *file)
{
	file->parsing_functions[0] = ambient_light_parsing;
	file->parsing_functions[1] = camera_parsing;
	file->parsing_functions[2] = light_parsing;
	file->parsing_functions[3] = cylinder_parsing;
	file->parsing_functions[4] = plane_parsing;
	file->parsing_functions[5] = sphere_parsing;
}
