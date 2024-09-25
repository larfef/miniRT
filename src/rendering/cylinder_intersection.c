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

static void	get_discriminant(t_vector *ray, t_vector oc, t_shapes *cy, t_quadratic *params)
{
	float	radius;

	radius = cy->size[DIAMETER] / 2;

	params->a = dot_product(*ray, *ray);
	params->h = 2 * dot_product(*ray, oc);;
	params->c = dot_product(oc, oc) - (radius * radius) * dot_product(cy->orientation, cy->orientation);
	params->discriminant = (params->h * params->h) - (4 * params->a * params->c);
}

static void	get_solutions(t_quadratic *params)
{
	float sqrt_discriminant;

	sqrt_discriminant = sqrt(params->discriminant);
	params->t1 = (-params->h - sqrt_discriminant) / (2 * params->a);
	params->t2 = (-params->h + sqrt_discriminant) / (2 * params->a);
}

static bool is_part_of_the_cylinder(t_vector *ray, float t, t_shapes *cylinder, float height) {
	t_vector P = {0};
	t_vector CP = {0};
	t_vector center = {0};

	center.dir = cylinder->center;
	float length;

	// Compute intersection point P along the ray
	P = add_vector(*ray, multiply_vector(*ray, t));
	// Vector from the cylinder center to intersection point P
	CP = sub_vector(P, center);

	// Project CP onto the cylinder's orientation vector to find its length along the cylinder's height
	length = dot_product(CP, cylinder->orientation);

	// Correct height check: check against half-height around center
	if (length >= -height / 2 && length <= height / 2) {
		return true;
	}

	return false;
}

//debug function

#include <stdio.h>
void	debug_brightness(float a)
{
	FILE *file = fopen("out1.txt", "a");

	if (file == NULL) {
		printf("Error opening file for writing.\n");
		return;
	}

	// Write the brightness factor to the file
	fprintf(file, "Brightness Factor: %f\n", a);

	// Close the file
	fclose(file);
}

float cylinder_intersection(t_shapes *cylinder, t_vector *ray) {
	t_vector DV = {0};
	t_vector COV;
	t_quadratic params = {0};

	DV = cross_product(*ray, cylinder->orientation);

	COV = cross_product(cylinder->camera_to_center, cylinder->orientation);

	get_discriminant(&DV, COV, cylinder, &params);

	if (params.discriminant < 0) {
		return (-1.0f);  // No intersection
	}

	get_solutions(&params);

	// Ensure intersections are checked correctly within cylinder height
	if (params.t1 >= 0 && is_part_of_the_cylinder(ray, params.t1, cylinder, cylinder->size[HEIGHT])) {
		debug_brightness(params.t1);
		return (params.t1);
	}

	if (params.t2 >= 0 && is_part_of_the_cylinder(ray, params.t2, cylinder, cylinder->size[HEIGHT])) {
		debug_brightness(params.t2);
		return (params.t2);
	}

	return (-1.0f);  // No valid intersection
}

