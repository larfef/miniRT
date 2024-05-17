/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:47:26 by rkersten          #+#    #+#             */
/*   Updated: 2024/05/17 20:59:30 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

void	open_file(t_file *file)
{
	int8_t	fd;

	file->fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
}

static	bool	skip_empty_line(char *c)
{
	if (c == '\n')
		return (true);
	return (false);
}

static bool	is_space(char c)
{
	if (c == 32
		|| c >= 8 && c <= 12)
		return (true);
	return (false);
}

static	void	skip_space(char **p)
{
	while (**p == 32
		|| (**p >= 8 && **p <= 12))
		(*p)++;
}

static bool is_duplicate_element(t_parsing *file_data)
{
	if ((file_data->current_line == AMBIENT && file_data->is_ambient)
		|| (file_data->current_line == CAMERA && file_data->is_camera)
		|| (file_data->current_line == LIGHT && file_data->is_light))
		return (true);
	return (false);
}

static void	set_duplicate_check(t_parsing *file_data)
{
	if (file_data->current_line == AMBIENT)
		file_data->is_ambient = true;
	if (file_data->current_line == CAMERA)
		file_data->is_camera = true;
	if (file_data->current_line == LIGHT)
		file_data->is_light = true;
}

static void	set_current_line(t_parsing *file_data)
{
	if (!ft_strncmp(&c, "A ", 2))
		file_data->current_line = AMBIENT;
	else if (!ft_strncmp(&c, "C ", 2))
		file_data->current_line = CAMERA;
	else if (!ft_strncmp(&c, "L ", 2))
		file_data->current_line = LIGHT;
	else if (!ft_strncmp(&c, "cy ", 3))
		file_data->current_line = CYLINDER;
	else if (!ft_strncmp(&c, "pl ", 3))
		file_data->current_line = PLANE;
	else if (!ft_strncmp(&c, "sp ", 3))
		file_data->current_line = SPHERE;
	else if (c == '\n')
		file_data->current_line = NEWLINE;
	else
		file_data->current_line = INVALID;
}

static bool	is_valid_character(char **p, char c, t_parsing *file_data)
{
	if (c == 'A' || c == 'L' || c == 'C')
	{
		if (c == 'A')
			file_data->is_ambient = true;
		if (c == 'C')
			file_data->is_camera = true;
		if (c == 'L')
			file_data->is_light = true;
		*p += 1;
		return (true);
	}
	if (!ft_strncmp(&c, "cy ", 3)
		|| !ft_strncmp(&c, "pl ", 3)
		|| !ft_strncmp(&c, "sp ", 3))
	{
		*p += 2;
		return (true);
	}
	return (false);
}

static bool	is_in_range(char *str, int type, int range[2])
{
	//double
	if (type == 0)
	{
		tmp = ft_atod(str);
		if (tmp >= (double)range[0] && tmp <= (double)range[1])
			return (true);
	}
	//int
	if (type == 1)
	{
		tmp = ft_atoi(str)
		if (tmp >= range[0] && tmp <= range[1])
			return (true);
	}
	return (false);
}

static bool	ambient_light_parsing(char *line)
{
	int	range[2] = {0, 1};

	if (!is_in_range(line, 0, range))
		return (1);;
	line += 3;
	skip_space();
	range[0] = 0;
	range[1] = 255;
	if (is_in_range())
}

static bool	parse_line(const char *line, t_parsing *file_data)
{
	skip_space(&line);
	set_current_line(file_data);
	if (file_data->current_line == INVALID)
		return (1);
	if (file_data->current_line == NEWLINE)
		return (0);
	skip_space(&line);
}

void	read_file(t_file *file, t_scene *scene, t_parsing *file_data)
{
	open_file(file);
	while (1)
	{
		file->line = get_next_line(file->fd);
		if (!file->line)
			return ;
		if (parse_line(file->line, file_data))
		{
			free(file->line);
			return ;
		}
		free(file->line);
	}
}