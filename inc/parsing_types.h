/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 16:48:58 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TYPES_H
# define PARSING_TYPES_H
# include <stdbool.h>
# include <stdint.h>
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
	CYLINDER,
	INVALID,
	LIGHT,
	PLANE,
	NEWLINE,
	SPHERE
}	t_element_type;
typedef struct s_file_info
{
	uint8_t	cylinder_count;
	uint8_t	plane_count;
	uint8_t	shpere_count;
}	t_file_info;
typedef struct s_file
{
	bool		is_ambient;
	bool		is_light;
	bool		is_camera;
	char		*line;
	char const	*file;
	uint8_t		errnum;
	int32_t		fd;
	t_element_type	current_line;
}	t_file;
#endif