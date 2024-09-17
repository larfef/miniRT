#include "../inc/types.h"
#include "../inc/rendering.h"

void    init_fct_ptr_normal(fct_ptr_normal *fct_ptr)
{
    fct_ptr[0] = set_cylinder_normal_vector;
    fct_ptr[1] = set_plane_normal_vector;
    fct_ptr[2] = set_sphere_normal_vector;
}
