#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANAGEMENT_H
# include "window_management_types.h"
# include "window_management_constant.h"
# include "init_stack_types.h"
void		display(t_scene *scene, t_window *window);
t_vector	pixel00_loc(t_vector (*pixel_delta)[2], t_vector viewport_upper_left);
void		set_aspect_ratio(float x, float y, float *aspect_ratio);
void		set_window_height(float width, float aspect_ratio, int *height);
void		set_image_width(int width, int *image_width);
void		set_pixel_delta(int32_t image_width, int32_t image_height,
							t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2]);
void		set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2], int hfov);
void		set_viewport_vectors(float (*viewport)[2], t_vector (*viewport_vectors)[2], t_vector *w);
void		create_window(t_window *window, t_scene *scene);
t_point 	upper_left_pixel(t_point camera_center, t_vector (*viewport_vectors)[2], t_vector w);
float		degrees_to_radian(float degrees);
t_vector	get_vup(t_vector *w);
#endif