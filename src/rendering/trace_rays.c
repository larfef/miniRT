#include "../inc/types.h"
#include "../inc/operation.h"
#include "../inc/rendering.h"
#include "../inc/constant.h"

void	set_sphere_normal_vector(t_ray_tracing *raytracer, t_point a, t_point b)
{
	raytracer->normal.dir = sub_point(a, b);
}

void	set_intersection_point(t_ray_tracing *raytracer)
{
	raytracer->hit_point_to_light.origin = add_point(raytracer->camera_to_viewport.origin,
													 multiply_point(raytracer->camera_to_viewport.dir,
																	raytracer->solution));
}

bool	check_intersection_with_shapes(t_vector *ray, t_shapes *shapes, intersection_t *fct_ptr_array, t_shapes *current)
{
	t_shapes	*shape;

	shape = shapes;
	while (shape)
	{
		if (shape != current)
			if (fct_ptr_array[shape->type](shape, ray) != -1.0f)
				return (true);
		shape = shape->next;
	}
	return (false);
}

typedef struct	s_jittering_grid
{
	int 	x;
	int 	y;
	int 	z;
	int 	shadow_hits;
	float	offset_x;
	float	offset_y;
	float	offset_z;
}	t_jittering_grid;

t_vector	generate_grid_shadow_ray(t_vector *ray, t_jittering_grid *grid)
{
	t_vector	shadow_ray;

	shadow_ray.origin = ray->origin;
	grid->offset_x = ((float)grid->x / (GRID_SIZE - 1) - 0.5f) * 0.1f;
	grid->offset_y = ((float)grid->y / (GRID_SIZE - 1) - 0.5f) * 0.1f;
	grid->offset_z = ((float)grid->z / (GRID_SIZE - 1) - 0.5f) * 0.1f;
	shadow_ray.dir.x = ray->dir.x + grid->offset_x;
	shadow_ray.dir.y = ray->dir.y + grid->offset_y;
	shadow_ray.dir.z = ray->dir.z + grid->offset_z;
	return (shadow_ray);
}

float	jittering_grid(t_scene *scene, t_ray_tracing * raytracer)
{
	float				shadow_factor;
	t_vector			shadow_ray;
	t_jittering_grid	grid = {0};

	grid.x = -1;
	while (++grid.x < GRID_SIZE)
	{
		grid.y = -1;
		while (++grid.y < GRID_SIZE)
		{
			grid.z = -1;
			while (++grid.z < GRID_SIZE)
			{
				shadow_ray = generate_grid_shadow_ray(&raytracer->hit_point_to_light, &grid);
				if (check_intersection_with_shapes(&shadow_ray, scene->shapes, scene->intersection, raytracer->shape))
					grid.shadow_hits++;
			}
		}
	}
	if (!grid.shadow_hits)
		return (0.0f);
	shadow_factor = (float)(NB_OF_RAY - grid.shadow_hits) / NB_OF_RAY;
	return (shadow_factor);
}

void	trace_rays(t_scene *scene, t_ray_tracing *raytracer)
{
	float	shadow_factor;

	if (raytracer->solution > 0.0)
	{
		set_intersection_point(raytracer);
		raytracer->hit_point_to_light.dir = sub_point(scene->light.coordinates,
													  raytracer->hit_point_to_light.origin);
//		raytracer->normal = cylinder_normal(shape, (t_vector){{0, 0, 0}, raytracer.hit_point_to_light.origin});
//		if (check_intersection_with_shapes(&raytracer->hit_point_to_light, scene->shapes, scene->intersection, raytracer->shape))
//		{
//			raytracer->color.color = 0x00000000;
//			return ;
//		}
		shadow_factor = jittering_grid(scene, raytracer);
		if (!shadow_factor)
		{
			set_sphere_normal_vector(raytracer, raytracer->hit_point_to_light.origin, raytracer->shape->center);
			set_pixel_color(raytracer, scene->light.brightness, raytracer->shape->color);
		}
		else
		{
			raytracer->color.t_rgba.red = (uint8_t)(((float)raytracer->color.t_rgba.red) * shadow_factor);
			raytracer->color.t_rgba.green = (uint8_t)(((float)raytracer->color.t_rgba.green) * shadow_factor);
			raytracer->color.t_rgba.blue = (uint8_t)(((float)raytracer->color.t_rgba.blue) * shadow_factor);
		}
	}
	else
		raytracer->color.color = scene->ambient.color.color;
}
