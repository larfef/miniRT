/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:06:17 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/31 16:45:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "parsing_types.h"
# include "parsing_constant.h"
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
bool	ambient_light_parsing(char *line);
bool	camera_parsing(char *line);
bool	is_orientation_valid(char **p);
bool	is_fov_valid(char **p);
bool	cylinder_parsing(char *line);
bool	error_message(char const *s, int errnum);
void	__exit(t_file *file, char *error_message);
double 	ft_atod(const char *str);
float	ft_atof(const char *str);
void	init_instructions(int **p);
void	init_parsing_functions(t_file *file);
bool	is_brightness_valid(char **line);
bool	is_digit(char **p);
bool	is_fov_valid(char **p);
bool	is_length_valid(char *s, int8_t lenght_max);
bool	is_light_ratio_valid(char **line);
bool	is_rgb_valid(char **p);
bool	is_coordinates_valid(char **p);
bool	is_duplicate(t_file *file);
bool	is_end_of_line_valid(char **line);
void	is_file_valid(char const *filename);
void	is_filename_valid(char const *filename);
bool	is_line_valid(int **tab, t_file *file);
bool	is_minimal_scene_valid(t_file *file);
bool	light_parsing(char *line);
void	open_file(t_file *file);
void	parse_line(t_file *file_data);
bool	plane_parsing(char *line);
void	read_file(t_file *file);
void	set_duplicate_check(t_file *file_data);
void	set_current_line_type(t_file *file_data);
bool	sphere_parsing(char *line);
void	skip_line_start(t_element_type type, char **p);
bool	skip_digit(char **p);
bool	skip_float(char **p);
bool	skip_space(char **p);
#endif