/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-win <gde-win@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:32 by gde-win           #+#    #+#             */
/*   Updated: 2024/09/27 14:42:09 by gde-win          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*
	@dev:	Initializes an array of function pointers in the `t_file` structure
			with specific parsing and validation functions. Each function in
			this array is responsible for validating or skipping a particular
			element of the scene description (e.g., brightness, coordinates,
			light ratio, RGB values, etc.). These functions are called during
			the parsing process based on the instruction arrays.

	@param:	file: a pointer to the `t_file` structure, where the parsing
			functions will be stored in the `parsing_functions` array. This
			array contains function pointers that validate or skip specific
			data types (e.g., coordinates, sizes, orientation) in the scene.
*/

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
	file->parsing_functions[11] = is_size_valid;
}
