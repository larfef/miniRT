#ifndef INIT_STACK_TYPES_H
# define INIT_STACK_TYPES_H
# include <stdint.h>
//typedef uint64_t		nb_elements[3];
typedef uint8_t			rgb[3];
typedef float			coordinates[3];
typedef float			size[2];
typedef float			orientation[3];
typedef void *			scene_datas[4];
typedef struct s_shapes	t_shapes;
typedef enum e_shape_types
{
	_CYLINDER,
	_PLANE,
	_SPHERE,
}	t_shape_type;
typedef enum	e_scene_elements
{
	_AMBIENT,
	_CAMERA,
	_LIGHT,
	_SHAPES,
}	t_elements_types;
typedef struct s_shapes
{
	coordinates 	center;
	orientation		orientation;
	rgb				color;
	size			size;
	t_shape_type	type;
	uint64_t		list_pos;
	t_shapes		*next;
}	t_shapes;
typedef struct s_ambient
{
	rgb		color;
	float	light_ratio;
} t_ambient;
typedef struct s_camera
{
	coordinates	coordinates;
	orientation	orientation;
	uint8_t		fov;
}	t_camera;
typedef struct s_light
{
	coordinates	coordinates;
	float		brightness;
}	t_light;
typedef struct s_scene
{
//	nb_elements	nb_elements;
	scene_datas scene;
}	t_scene;
#endif