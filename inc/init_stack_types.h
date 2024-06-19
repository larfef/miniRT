#ifndef INIT_STACK_TYPES_H
# define INIT_STACK_TYPES_H
# include <stdint.h>
# include "window_management_types.h"
# include "types.h"
typedef float			size[2];
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
typedef union	u_color
{
	uint32_t color;
	struct	s_rgba
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	} t_rgba;
} color;
typedef struct s_shapes
{
	t_vector		center;
	t_vector		orientation;
	color			color;
	size			size;
	t_shape_type	type;
	uint64_t		list_pos;
	t_shapes		*next;
}	t_shapes;
typedef struct s_ambient
{
	color 	color;
	float	light_ratio;
} t_ambient;
typedef struct s_camera
{
	t_vector	coordinates;
	t_vector	orientation;
	uint8_t		fov;
}	t_camera;
typedef struct s_light
{
	t_vector	coordinates;
	float		brightness;
}	t_light;
typedef struct s_scene
{
	t_ambient			ambient;
	t_camera			camera;
	t_light				light;
	t_shapes 			*shapes;
	t_elements_types	element_type;
}	t_scene;
#endif