#include "../inc/types.h"
#include "../inc/operation.h"
#include "../inc/rendering.h"
#include "../inc/constant.h"
#include "../libft/inc/libft.h"

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_point(raytracer->camera_to_viewport.origin,
													 multiply_point(raytracer->camera_to_viewport.dir,
																	raytracer->solution));
}

void	set_shadow_color(color *color, const float shadow_factor)
{
	color->t_rgba.red = (uint8_t)(((float)color->t_rgba.red) * shadow_factor);
	color->t_rgba.green = (uint8_t)(((float)color->t_rgba.green) * shadow_factor);
	color->t_rgba.blue = (uint8_t)(((float)color->t_rgba.blue) * shadow_factor);
}

void	set_ambient_color(t_ray_tracing *rt, const uint32_t color, const float ambient_factor)
{
	rt->color.color = color;
	rt->color.t_rgba.red = (float)rt->color.t_rgba.red * ambient_factor;
	rt->color.t_rgba.green = (float)rt->color.t_rgba.green * ambient_factor;
	rt->color.t_rgba.blue = (float)rt->color.t_rgba.blue * ambient_factor;
}

void	trace_rays(t_scene *scene, t_ray_tracing *rt)
{
	t_jittering_grid	grid = {0};
	t_vector			camera_to_hit_point;

	//should be removed
	rt->is_inside = false;
	if (rt->solution > 0.0f)
	{
		camera_to_hit_point = multiply_vector(rt->camera_to_viewport, rt->solution);
		rt->distance_from_camera = length(camera_to_hit_point);
		set_intersection_point(rt);
		rt->hit_point_to_light.dir = sub_point(scene->light.coordinates,rt->hit_point_to_light.origin);
		rt->set_normal_vector[rt->shape->type](rt);
		set_pixel_color(rt, scene->light.brightness, rt->shape->color);
		if (get_cos(rt->hit_point_to_light, rt->normal) > GRADIENT_END)
			jittered_grid(scene, rt, &grid);
		set_shadow_color(&rt->color, grid.shadow_factor);
	}
	else
		set_ambient_color(rt, scene->ambient.color.color, scene->ambient.light_ratio);
}
