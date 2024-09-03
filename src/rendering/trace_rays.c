#include "../inc/types.h"
#include "../inc/operation.h"
#include "../inc/rendering.h"
#include "../inc/constant.h"

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_point(raytracer->camera_to_viewport.origin,
													 multiply_point(raytracer->camera_to_viewport.dir,
																	raytracer->solution));
}

static bool	check_conditions(const t_ray_tracing *rt, const t_shapes *shape)
{
	if (rt->shape->type == _CYLINDER && rt->is_inside == true)
		return (true);
	if (shape == rt->shape)
		return (false);
	if (get_cos(rt->normal, rt->hit_point_to_light) < GRADIENT_END)
		return (false);
	return (true);
}

//version where we check if the intersection append if a distance smaller than the distance between the hit point and
// the light
bool	check_intersection_with_shapes(t_vector *ray, t_shapes *shapes, intersection_t *fct_ptr_array, t_ray_tracing *rt)
{
	t_shapes	*shape;
	t_vector	result;
	float		ret;

	shape = shapes;
	while (shape)
	{
		if (check_conditions(rt, shape) == true)
		{
			ret = fct_ptr_array[shape->type](shape, ray);
			if (ret != -1.0f)
			{
				result = multiply_vector(*ray, ret);
				if (length(result) <= length(*ray))
					return (true);
			}
		}
		shape = shape->next;
	}
	return (false);
}
t_vector	generate_grid_shadow_ray(const t_vector *ray, t_jittering_grid *grid)
{
	t_vector	shadow_ray;

	shadow_ray.origin = ray->origin;
	grid->offset_x = ((float)grid->x / (GRID_SIZE - 1) - 0.5f) * 1.0f;
	grid->offset_y = ((float)grid->y / (GRID_SIZE - 1) - 0.5f) * 1.0f;
	grid->offset_z = ((float)grid->z / (GRID_SIZE - 1) - 0.5f) * 1.0f;
	shadow_ray.dir.x = ray->dir.x + grid->offset_x;
	shadow_ray.dir.y = ray->dir.y + grid->offset_y;
	shadow_ray.dir.z = ray->dir.z + grid->offset_z;
	return (shadow_ray);
}

void	jittering_grid(t_scene *scene, t_ray_tracing * raytracer, t_jittering_grid *grid)
{
	t_vector			shadow_ray = {0};

	grid->x = -1;
	while (++grid->x < GRID_SIZE)
	{
		grid->y = -1;
		while (++grid->y < GRID_SIZE)
		{
			grid->z = -1;
			while (++grid->z < GRID_SIZE)
			{
				shadow_ray = generate_grid_shadow_ray(&raytracer->hit_point_to_light, grid);
				if (check_intersection_with_shapes(&shadow_ray, scene->shapes, scene->intersection, raytracer))
					grid->shadow_hits++;
			}
		}
	}
	grid->shadow_factor = (float)(NB_OF_RAY - grid->shadow_hits) / NB_OF_RAY;
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
	t_jittering_grid	grid = {0};

	raytracer->is_inside = false;
	if (raytracer->solution > 0.0f)
	{
		set_intersection_point(raytracer);
		raytracer->hit_point_to_light.dir = sub_point(scene->light.coordinates,
													  raytracer->hit_point_to_light.origin);
		raytracer->set_normal_vector[raytracer->shape->type](raytracer);
		set_pixel_color(raytracer, scene->light.brightness, raytracer->shape->color);
		if (get_cos(raytracer->hit_point_to_light, raytracer->normal) > GRADIENT_END)
			jittering_grid(scene, raytracer, &grid);
		set_shadow_color(&raytracer->color, grid.shadow_factor);
	}
	else
		set_ambient_color(raytracer, scene->ambient.color.color, scene->ambient.light_ratio);
}
