#include "../../inc/operation.h"
#include "../../inc/constant.h"
#include <math.h>

// float   plane_linear_equation(t_vector *normal, t_point *origin, t_point *direction)
// {
//     float   solution;
//     float   denominator;
//     float   numerator;
//     float   D;
//
//     D = dot_product(*normal, (t_vector){{0,0,0}, *direction});
//     numerator = (-1 * ((normal->origin.x * origin->x)
//                 + (normal->origin.y * origin->y)
//                 + (normal->origin.z * origin->z))
//                 + D);
//     denominator = ((normal->dir.x * direction->x)
//                     + (normal->dir.y * direction->y)
//                     + (normal->dir.z * direction->z));
//     if (denominator == 0)
//         return (-1.0f);
//     solution = numerator / denominator;
//     if (solution > 0 )
//         return (solution);
//     return (-1.0f);
// }

float plane_linear_equation(t_vector *normal, t_point *point_on_plane, t_point *ray_origin, t_point *ray_direction)
{
	float numerator;
	float denominator;
	float t;

	// Calculate denominator: dot product of plane normal and ray direction
	denominator = dot_product(*normal, (t_vector){{0,0,0}, *ray_direction});

	// Check if ray is parallel to the plane
	if (fabs(denominator) < EPSILON)
		return (-1.0f);  // No intersection, ray is parallel to the plane

	// Vector from ray origin to a point on the plane
	t_vector ray_to_plane;
	ray_to_plane.dir = sub_point(*point_on_plane, *ray_origin);

	// Calculate numerator: dot product of normal and ray_to_plane vector
	numerator = dot_product(*normal, ray_to_plane);

	// Calculate intersection point `t`
	t = numerator / denominator;

	// Ensure the intersection is in front of the ray origin
	if (t > 0)
		return t;

	return (-1.0f);  // No valid intersection, behind ray origin
}

float plane_intersection(t_shapes *plane, t_vector *ray)
{
	return plane_linear_equation(&plane->orientation, &plane->center, &ray->origin, &ray->dir);
}