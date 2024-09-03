#include "../inc/types.h"
#include "../inc/operation.h"

void	set_sphere_normal_vector(t_ray_tracing *raytracer)
{
    raytracer->normal.dir = sub_point(raytracer->hit_point_to_light.origin, raytracer->shape->center);
}

void	set_cylinder_normal_vector(t_ray_tracing *rt)
{
    rt->normal = cylinder_normal(rt->shape, (t_vector){{0, 0, 0}, rt->hit_point_to_light.origin});
    if (dot_product(rt->normal, rt->camera_to_viewport) > 0)
    {
        rt->is_inside = true;
        rt->normal = multiply_vector(rt->normal, -1);
    }
    else
        rt->is_inside = false;
}

void	set_plane_normal_vector(t_ray_tracing *rt)
{
    rt->normal = rt->shape->orientation;
    if (rt->shape->type == _PLANE
        && get_cos(rt->hit_point_to_light, rt->normal) < 0)
        rt->normal = multiply_vector(rt->normal, -1);
}
