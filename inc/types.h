/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 21:42:31 by rkersten          #+#    #+#             */
/*   Updated: 2024/03/25 17:06:25 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# include "library.h"

typedef struct s_color		t_color;
typedef struct s_coordinate	t_coordinate;
typedef struct s_vector		t_vector;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_cylinder	t_cylinder;
typedef struct s_light		t_light;
typedef struct s_plane		t_plane;
typedef struct s_scene		t_scene;
typedef struct s_sphere		t_sphere;
typedef struct s_color
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
}	t_color;
typedef struct s_coordinate
{
	float	x;
	float	y;
	float	z;
}	t_coordinate;
typedef struct s_vector
{
	int8_t	x;
	int8_t	y;
	int8_t	z;
}	t_vector;
typedef struct s_ambient
{
	float	lighting_ratio;
	t_color	color;
}	t_ambient;
typedef struct s_camera
{
	uint8_t			fov;
	t_coordinate	pos;
	t_vector		vector;
}	t_camera;
typedef struct s_file_info
{
	bool	ambient;
	bool	camera;
	bool	light;
	uint8_t	cylinder_count;
	uint8_t	plane_count;
	uint8_t	shpere_count;
}	t_file_info;
typedef struct s_cylinder
{
	float			diameter;
	float			height;
	t_coordinate	center;
	t_color			color;
	t_vector		axis;
}	t_cylinder;
typedef struct s_file
{
	char const	*filename;
	char		*line;
	int32_t		fd;
	t_file_info	content;
}	t_file;
typedef struct s_light
{
	float			brightness;
	t_color			color;
	t_coordinate	pos;
}	t_light;
typedef struct s_plane
{
	t_coordinate	point;
	t_color			color;
	t_vector		vector;
}	t_plane;
typedef struct s_scene
{
	t_ambient	ambient;
	t_cylinder	*cylinders;
	t_light		light;
	t_plane		*planes;
	t_sphere	*spheres;
}	t_scene;
typedef struct s_sphere
{
	float			diameter;
	t_color			color;
	t_coordinate	center;
}	t_sphere;
#endif