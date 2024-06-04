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
# include "init_stack_types.h"
# include <stdint.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
bool	is_orientation_valid(char **p, t_scene *scene, int option);
void	__exit(t_file *file, char *error_message);
float	ft_atof(const char *str);
void	init_file(t_file *file, char *filename);
void	init_instructions(int **p);
void	init_parsing_functions(t_file *file);
bool	is_brightness_valid(char **line, t_scene *scene, int option);
bool	is_digit(char **p, t_scene *scene, int option);
bool	is_fov_valid(char **p, t_scene *scene, int option);
bool	is_length_valid(char *s, int8_t lenght_max);
bool	is_light_ratio_valid(char **line, t_scene *scene, int option);
bool	is_rgb_valid(char **p, t_scene *scene, int option);
bool	is_size_valid(char **line, t_scene *scene, int option);
bool	is_coordinates_valid(char **p, t_scene *scene, int option);
bool	is_duplicate(t_file *file);
bool	is_end_of_line_valid(char **line, t_scene *scene, int option);
void	is_file_valid(t_file *file);
void	is_filename_valid(char const *filename);
bool	is_line_valid(int **tab, t_file *file);
bool	is_minimal_scene_valid(t_file *file);
void	open_file(t_file *file);
void	parse_line(t_file *file_data);
void	read_file(t_scene *scene, t_file *file, int option);
void	set_duplicate_check(t_file *file_data);
void	set_current_line_type(t_file *file_data);
void	skip_line_start(int type, char **p);
bool	skip_digit(char **p, t_scene *scene, int option);
bool	skip_float(char **p, t_scene *scene, int option);
bool	skip_space(char **p, t_scene *scene, int option);
#endif