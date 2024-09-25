#ifndef TYPES_H
# define TYPES_H
# include <stdint.h>
# include <stdbool.h>
typedef struct s_shapes	t_shapes;
typedef struct s_vector t_vector;
typedef struct s_ray_tracing t_ray_tracing;
typedef float	(*intersection_t)(t_shapes *, t_vector *);
typedef void (*fct_ptr_normal)(t_ray_tracing *rt);
typedef struct	s_point
{
	float	x;
	float	y;
	float	z;
}	t_point;
typedef	struct	s_vector
{
	t_point		origin;
	t_point		dir;
}	t_vector;
typedef float	size[2];
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
		uint8_t blue;
		uint8_t green;
		uint8_t red;
		uint8_t alpha;
	} t_rgba;
} color;
typedef struct	s_jittering_grid
{
	int 	x;
	int 	y;
	int 	z;
	int 	shadow_hits;
	float	offset_x;
	float	offset_y;
	float	offset_z;
	float	shadow_factor;
}	t_jittering_grid;
typedef	struct s_ray_tracing
{
	bool		is_inside;
	color		color;
	t_vector	camera_to_viewport;
	t_vector	camera_to_hit_point;
	t_vector	hit_point_to_light;
	t_point		pixel_center;
	t_vector	normal;
	float		solution;
	float		distance_from_camera;
	t_shapes	*shape;
	fct_ptr_normal	set_normal_vector[3];
}	t_ray_tracing;
typedef struct	s_quadratic
{
	float	a;
	float	c;
	float	discriminant;
	float	h;
	float	t1;
	float	t2;
	t_vector	v;
}	t_quadratic;
typedef struct s_shapes
{
	t_vector		camera_to_center;
	t_point			center;
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
	t_point		coordinates;
	t_vector	orientation;
	uint8_t		fov;
}	t_camera;
typedef struct s_light
{
	t_point		coordinates;
	float		brightness;
}	t_light;
typedef struct s_scene
{
	t_ambient			ambient;
	t_camera			camera;
	t_light				light;
	t_shapes 			*shapes;
	t_elements_types	element_type;
	intersection_t		intersection[3];
}	t_scene;
typedef struct	s_solver
{
	t_vector	CO;
	t_vector	center;
	t_vector	v;
	t_vector	D;
	float r;
}	t_solver;
typedef struct s_intersection
{
	t_vector	ray;
	t_solver	solver;
}	t_intersection;
typedef bool	(*func_ptr_t)(char **, t_scene *, int);
//typedef float	(*color)()
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
	func_ptr_t		parsing_functions[12];
	int32_t			fd;
	int 			**instructions;
	t_element_type	current_line;
}	t_file;
typedef float	viewport[2];
typedef struct s_window
{
	void		*mlx;
	void		*window;
	int 		width;
	int 		height;
	float		aspect_ratio;
	viewport	viewport;
	t_vector	viewport_vectors[2];
	t_vector	pixel_delta[2];
	t_point		focal_length;
	t_point		pixel00_loc;
	t_point		viewport_upper_left;
}	t_window;
typedef struct s_hook
{
	void		*mlx;
	void		*window;
	t_shapes	*shapes;
}	t_hook;
#endif