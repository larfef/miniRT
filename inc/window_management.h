/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:34:14 by rkersten          #+#    #+#             */
/*   Updated: 2024/10/04 14:43:00 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_MANAGEMENT_H
# define WINDOW_MANAGEMENT_H
# include "types.h"
# include "constant.h"
# include <stdint.h>

void		create_window(t_window *window, t_scene *scene);
void		exit_error(t_window *ptr, t_shapes *list);
t_vector	get_vup(t_vector *w);
void		init_window_struct(t_scene *scene, t_window *win);
void		init_struct(t_window *win, t_ray_tracing *rt, t_file *file);
t_color		ray_color(t_vector *direction);
t_color		set_color(float r, float g, float b);
void		set_pixel_center(t_window *win, t_point *pixel_center);
void		set_pixel_delta(int32_t image_width, int32_t image_height,
				t_vector (*viewport_vectors)[2], t_vector (*pixel_delta)[2]);
void		set_pixel00_loc(t_vector (*pixel_delta)[2],
				t_point viewport_upper_left, t_point *pixel00_loc);
void		set_viewport(int32_t image_width, int32_t image_height,
				float (*viewport)[2], int hfov);
void		set_viewport_vectors(float (*viewport)[2],
				t_vector (*viewport_vectors)[2], t_vector *w);
void		set_window_height(float width, float aspect_ratio, int *height);
void		set_upper_left_pixel(t_point camera_center,
				t_vector (*viewport_vectors)[2], t_vector w, t_point *pos);
#endif
