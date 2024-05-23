/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:06:17 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/23 13:29:50 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "parsing_types.h"
# include <stdint.h>
# include <stdbool.h>
bool	ambient_light_parsing(char *line);
bool	camera_parsing(char *line);
bool	check_3d_vector(char **p);
bool	is_brightness_valid(char *line);
bool	is_length_valid(char *s, int8_t lenght_max);
bool	check_rgb(char **p);
bool	is_coordinates_valid(char **p);
bool	is_duplicate_element(t_file *file_data);
bool	is_end_of_line_valid(char *line);
bool	is_in_range(char **p, int type);
bool	is_space(char c);
bool	is_valid_character(char **p, char c, t_file *file_data);
double 	ft_atod(const char *str);
void	open_file(t_file *file);
bool	parse_line(t_file *file_data);
void	read_file(t_file *file);
void	set_duplicate_check(t_file *file_data);
void	set_current_line_type(t_file *file_data);
void	skip_digit(char **p);
void	skip_double(char **p);
void	skip_space(char **p);
#endif