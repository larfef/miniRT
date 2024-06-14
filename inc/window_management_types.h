#ifndef WINDOW_MANAGEMENT_TYPE_H
#define WINDOW_MANAGEMENT_TYPE_H
# include "../src/mlx42/include/MLX42/MLX42.h"
typedef float	viewport[2];
//typedef float	vector[3];
typedef	struct	s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector;
typedef struct s_window
{
	mlx_t		mlx;
	mlx_image_t	*image;
	float		aspect_ratio;
	viewport	viewport;
	t_vector		viewport_vectors[2];
	t_vector		pixel_delta[2];
	t_vector		focal_length;
	t_vector		pixel00_loc;
	t_vector		viewport_upper_left;
}	t_window;
#endif