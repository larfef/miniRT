#ifndef WINDOW_MANAGEMENT_TYPE_H
#define WINDOW_MANAGEMENT_TYPE_H
# include "../src/mlx42/include/MLX42/MLX42.h"
typedef struct s_window
{
	mlx_t	mlx;
	float	aspect_ratio;
}	t_window;
#endif