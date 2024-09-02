#include "../../inc/types.h"
#include "../../inc/constant.h"
#include "../../inc/operation.h"
#include <math.h>

/*
 * need to add a check weither the light coordinate is inside or outside the cylinder
 * need to check if the visible part of the cylinder is the inside or the outside part
 */

typedef struct s_cy
{
	t_vector CO;
	t_vector center;
	t_vector v;
	t_vector D;
	float r;
}	t_cylinder;

static void	get_discriminant(t_vector *ray, t_vector oc, t_cylinder *cy, t_quadratic *params)
{
	params->a = dot_product(*ray, *ray);
	params->h = 2 * dot_product(*ray, oc);;
	params->c = dot_product(oc, oc) - (cy->r * cy->r) * dot_product(cy->v, cy->v);
	params->discriminant = (params->h * params->h) - (4 * params->a * params->c);
}
//
//static void	init_cylinder_struct(t_cylinder *cy, t_shapes *cylinder, t_vector *ray)
//{
//	cy->CO.dir = sub_point(ray->origin, cylinder->center);
//	cy->center.dir = cylinder->center;
//	cy->v = cylinder->orientation;
//	cy->D = *ray;
//	cy->r = cylinder->size[DIAMETER] / 2.0f;
//}
//
static void	get_solutions(t_quadratic *params)
{
	float sqrt_discriminant;

	sqrt_discriminant = sqrt(params->discriminant);
	params->t1 = (-params->h - sqrt_discriminant) / (2 * params->a);
	params->t2 = (-params->h + sqrt_discriminant) / (2 * params->a);
}
//
//static bool	is_part_of_the_cylinder(t_vector *ray, float t, t_cylinder *cy, float height)
//{
//	t_vector	P = {0};
//	t_vector	CP = {0};
//	float		length;
//
//	P = add_vector(*ray, multiply_vector(cy->D, t));
//	CP= sub_vector(P, cy->center);
//	length = dot_product(CP, cy->v);
//	if (length >= 0 && length <= height)
//		return (true);
//	return (false);
//}

//float	cylinder_intersection(t_shapes *cylinder, t_vector *ray) {
//
//	t_cylinder cy = {0};
//	t_vector DV = {0};
//	t_vector COV;
//	t_quadratic params = {0};
//
//	init_cylinder_struct(&cy, cylinder, ray);
//	DV = cross_product(cy.D, cy.v);
//	COV = cross_product(cy.CO, cy.v);
//	get_discriminant(&DV, COV, &cy, &params);
//	if (params.discriminant < 0)
//		return (-1.0f);
//	get_solutions(&params);
//	if (is_part_of_the_cylinder(ray, params.t1, &cy, cylinder->size[HEIGHT]))
//		return (params.t1);
//	if (is_part_of_the_cylinder(ray, params.t2, &cy, cylinder->size[HEIGHT]))
//		return (params.t2);
//	return (-1.0f);
//}

static void init_cylinder_struct(t_cylinder *cy, t_shapes *cylinder, t_vector *ray) {
	cy->v = cylinder->orientation;  // Cylinder's orientation vector
	cy->r = cylinder->size[DIAMETER] / 2;  // Radius of the cylinder
	cy->center.dir = cylinder->center;  // Center of the cylinder, as given
	cy->CO.dir = sub_point(ray->origin, cy->center.dir);  // Vector from ray origin to cylinder center
	cy->D = *ray;  // Ray direction
}

static bool is_part_of_the_cylinder(t_vector *ray, float t, t_cylinder *cy, float height) {
	t_vector P = {0};
	t_vector CP = {0};
	float length;

	// Compute intersection point P along the ray
	P = add_vector(*ray, multiply_vector(*ray, t));
	// Vector from the cylinder center to intersection point P
	CP = sub_vector(P, cy->center);

	// Project CP onto the cylinder's orientation vector to find its length along the cylinder's height
	length = dot_product(CP, cy->v);

	// Correct height check: check against half-height around center
	if (length >= -height / 2 && length <= height / 2) {
		return true;
	}

	return false;
}

float cylinder_intersection(t_shapes *cylinder, t_vector *ray) {
	t_cylinder cy = {0};
	t_vector DV = {0};
	t_vector COV;
	t_quadratic params = {0};

	init_cylinder_struct(&cy, cylinder, ray);

	DV = cross_product(cy.D, cy.v);
	COV = cross_product(cy.CO, cy.v);

	get_discriminant(&DV, COV, &cy, &params);

	if (params.discriminant < 0) {
		return (-1.0f);  // No intersection
	}

	get_solutions(&params);

	// Ensure intersections are checked correctly within cylinder height
	if (params.t1 >= 0 && is_part_of_the_cylinder(ray, params.t1, &cy, cylinder->size[HEIGHT])) {
		return (params.t1);
	}

	if (params.t2 >= 0 && is_part_of_the_cylinder(ray, params.t2, &cy, cylinder->size[HEIGHT])) {
		return (params.t2);
	}

	return (-1.0f);  // No valid intersection
}

