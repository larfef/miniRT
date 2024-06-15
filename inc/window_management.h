#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANAGEMENT_H
# include "window_management_types.h"
# include "window_management_constant.h"
# include "init_stack_types.h"
void	display(t_scene *scene, t_window *window);
void	set_aspect_ratio(float x, float y, float *aspect_ratio);
void	set_window_height(float width, float aspect_ratio, int32_t *height);
void	set_image_width(int width, int *image_width);
void	set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2]);
void	create_window(t_window *window, t_scene *scene);
#endif