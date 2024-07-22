#ifndef TYPES_H
#define TYPES_H
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
#endif