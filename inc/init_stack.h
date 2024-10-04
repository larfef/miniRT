/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:31:04 by rkersten          #+#    #+#             */
/*   Updated: 2024/09/03 18:39:00 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STACK_H
# define INIT_STACK_H
# include "types.h"

void	___exit(char *s, t_shapes *list);
void	free_list(t_shapes *list);
void	extract_file_data(t_file *file, t_scene *scene);
void	init_fct_ptr(t_scene *ptr);
void	init_fct_ptr_normal(t_normal *fct_ptr);
void	init_stack(t_scene *scene, t_file *file);
void	set_element_type(char c, t_elements_types *element_type);
void	set_shape_type(t_shape_type *type, char c);
#endif