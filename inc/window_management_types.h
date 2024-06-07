#ifndef WINDOW_MANAGEMENT_TYPE_H
#define WINDOW_MANAGEMENT_TYPE_H
# include "../src/mlx42/include/MLX42/MLX42.h"
typedef float	viewport[2];
typedef struct s_window
{
	mlx_t	mlx;
	mlx_image_t	*image;
	float	aspect_ratio;
	viewport	viewport;
}	t_window;
#endif