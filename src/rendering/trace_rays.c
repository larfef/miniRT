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

void	trace_rays(t_scene *scene, t_ray_tracing *raytracer)
{
//	t_jittering_grid	grid = {0};

	raytracer->is_inside = false;
	if (raytracer->solution > 0.0f)
	{
		set_intersection_point(raytracer);
		raytracer->hit_point_to_light.dir = sub_point(scene->light.coordinates,
													  raytracer->hit_point_to_light.origin);
		raytracer->set_normal_vector[raytracer->shape->type](raytracer);
		set_pixel_color(raytracer, scene->light.brightness, raytracer->shape->color);
//		if (get_cos(raytracer->hit_point_to_light, raytracer->normal) > GRADIENT_END)
//			jittered_grid(scene, raytracer, &grid);
//		set_shadow_color(&raytracer->color, grid.shadow_factor);
	}
	else
		set_ambient_color(raytracer, scene->ambient.color.color, scene->ambient.light_ratio);
//	else
//	{
//		raytracer->color = scene->ambient.color;
//		raytracer->color.t_rgba.red = (uint8_t)(((float)scene->ambient.color.t_rgba.red) * scene->ambient.light_ratio);
//		raytracer->color.t_rgba.green = (uint8_t)(((float)scene->ambient.color.t_rgba.green) * scene->ambient.light_ratio);
//		raytracer->color.t_rgba.blue = (uint8_t)(((float)scene->ambient.color.t_rgba.blue) * scene->ambient.light_ratio);
//	}
}
