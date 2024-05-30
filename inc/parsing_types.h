/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/29 14:03:01 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TYPES_H
# define PARSING_TYPES_H
# include <stdbool.h>
# include <stdint.h>
typedef bool	(*func_ptr_t)(char *);
typedef bool	mandatory_element[3];
typedef struct s_atod
{
	bool		is_fraction;
	char		sign;
	const char	*str;
	double		fractional_part;
	double 		fraction_divisor;
	double 		integer_part;
	double		result;
}	t_atod;

typedef enum s_element_type
{
	AMBIENT,
	CAMERA,
	LIGHT,
	CYLINDER,
	PLANE,
	SPHERE,
	INVALID,
	NEWLINE,
}	t_element_type;
typedef struct s_file_info
{
	uint8_t	cylinder_count;
	uint8_t	plane_count;
	uint8_t	shpere_count;
}	t_file_info;
typedef struct s_file
{
	mandatory_element	minimal_scene;
	char		*line;
	char		*line_start;
	char const	*file;
	func_ptr_t	parsing_functions[7];
	int32_t		fd;
	uint8_t		errnum;
	t_element_type	current_line;
}	t_file;
#endif