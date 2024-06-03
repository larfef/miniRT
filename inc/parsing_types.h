/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:48:00 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 12:49:19 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TYPES_H
# define PARSING_TYPES_H
# include <stdbool.h>
# include <stdint.h>
typedef bool	(*func_ptr_t)(char **);
//typedef bool	(*func_ptr_t)(char **, void *, int);
typedef bool	mandatory_element[3];
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
typedef struct s_file
{
	mandatory_element	minimal_scene;
	char			*line;
	char			*line_start;
	char const		*file;
	func_ptr_t		parsing_functions[11];
	int32_t			fd;
	int 			**instructions;
	t_element_type	current_line;
}	t_file;
#endif