#ifndef TYPES_H
#define TYPES_H
typedef struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;
typedef	struct	s_ray
{
	t_vector	origin;
	t_vector	dir;
}	t_ray;
#endif