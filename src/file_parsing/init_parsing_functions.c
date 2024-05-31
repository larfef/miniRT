/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:43:25 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:39:52 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
#include "../libft/inc/libft.h"

void	init_parsing_functions(t_file *file)
{
	file->parsing_functions[0] = is_brightness_valid;
	file->parsing_functions[1] = is_coordinates_valid;
	file->parsing_functions[2] = is_light_ratio_valid;
	file->parsing_functions[3] = is_rgb_valid;
	file->parsing_functions[4] = skip_float;
	file->parsing_functions[5] = skip_space;
	file->parsing_functions[6] = is_end_of_line_valid;
	file->parsing_functions[7] = is_orientation_valid;
	file->parsing_functions[8] = is_digit;
	file->parsing_functions[9] = is_fov_valid;
	file->parsing_functions[10] = skip_digit;
}
