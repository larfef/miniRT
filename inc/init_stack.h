#ifndef INIT_STACK_H
# define INIT_STACK_H
# include "init_stack_constant.h"
# include "init_stack_types.h"
# include "init_stack_constant.h"
# include "init_stack_types.h"
# include "parsing_types.h"
void	___exit(char *s, t_shapes *list);
void	extract_file_data(t_file *file, t_scene *scene);
void	init_stack(t_scene *scene, t_file *file);
void	set_element_type(char c, t_elements_types *element_type);
void	set_shape_type(t_shape_type *type, char c);
#endif