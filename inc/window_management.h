#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANAGEMENT_H
# include <stdint.h>
# include "types.h"
# include "constant.h"
void		create_window(t_window *window, t_scene *scene);
void		exit_error(t_window *ptr, t_shapes *list);
t_vector	get_vup(t_vector *w);
t_point		pixel00_loc(t_vector (*pixel_delta)[2], t_point viewport_upper_left);
color		ray_color(t_vector *direction);
void		set_aspect_ratio(float x, float y, float *aspect_ratio);
color		set_color(float r, float g, float b);
void		set_image_width(int width, int *image_width);
void		set_pixel_center(t_window *window, t_point *pixel_center, int x, int y);
void		set_pixel_delta(int32_t image_width, int32_t image_height,
							t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2]);
void		set_viewport(int32_t image_width, int32_t image_height, float (*viewport)[2],
						 int hfov);
void		set_viewport_vectors(float (*viewport)[2], t_vector (*viewport_vectors)[2],
								 t_vector *w);
void		set_window_height(float width, float aspect_ratio, int *height);
t_point 	upper_left_pixel(t_point camera_center, t_vector (*viewport_vectors)[2],
							 t_vector w);
#endif
