#ifndef WINDOW_MANAGEMENT_TYPE_H
#define WINDOW_MANAGEMENT_TYPE_H
# include "../src/mlx/mlx.h"
# include "types.h"
typedef float	viewport[2];
typedef struct s_window
{
	void	*mlx;
	void	*image;
	void	*window;
	int 	width;
	int 	height;
	int 	img_width;
	float		aspect_ratio;
	viewport	viewport;
	t_vector		viewport_vectors[2];
	t_vector		pixel_delta[2];
	t_vector		focal_length;
	t_vector		pixel00_loc;
	t_vector		viewport_upper_left;
}	t_window;
#endif