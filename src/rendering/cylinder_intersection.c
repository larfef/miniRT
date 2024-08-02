#include "../../inc/types.h"
#include "../../inc/constant.h"
#include "../../inc/operation.h"
#include <math.h>

/*
 * need to add a check weither the light coordinate is inside or outside the cylinder
 * need to check if the visible part of the cylinder is the inside or the outside part
 */

float	cylinder_intersection(t_shapes *cylinder, t_vector *ray) {
	t_vector CO = {0};
	t_vector cylinder_center = {0};
	CO.dir = sub_point(ray->origin, cylinder->center);
	cylinder_center.dir = cylinder->center;
	t_vector v = cylinder->orientation;
	t_vector D = *ray;
	float r = cylinder->size[DIAMETER] / 2;

	t_vector DV = cross_product(D, v);
	t_vector COV = cross_product(CO, v);
	float a = dot_product(DV, DV);
	float b = 2 * dot_product(DV, COV);
	float c = dot_product(COV, COV) - r * r * dot_product(v, v);

	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0) {
		return ((float)-1.0);
	}

	float sqrt_discriminant = sqrt(discriminant);
	float t1 = (-b - sqrt_discriminant) / (2 * a);
	float t2 = (-b + sqrt_discriminant) / (2 * a);

	if (t1 >= 0) {
		t_vector P1 = add_vector(*ray, multiply_vector(D, t1));
		t_vector CP1 = sub_vector(P1, cylinder_center);
		float projection_length1 = dot_product(CP1, v);
		if (projection_length1 >= 0 && projection_length1 <= cylinder->size[HEIGHT]) {
			return (t1);
		}
	}

	if (t2 >= 0) {
		t_vector P2 = add_vector(*ray, multiply_vector(D, t2));
		t_vector CP2 = sub_vector(P2, cylinder_center);
		float projection_length2 = dot_product(CP2, v);
		if (projection_length2 >= 0 && projection_length2 <= cylinder->size[HEIGHT]) {
			return (t2);
		}
	}
	return ((float)-1.0);
}
