#include "../inc/types.h"
#include "../inc/operation.h"

t_vector cylinder_normal(t_shapes *cylinder, t_vector point) {
	// Step 1: Calculate vector from cylinder center to point
	t_vector cylinder_center = {{0,0,0}, cylinder->center};

	t_vector CP = sub_vector(point, cylinder_center);

	// Step 2: Project CP onto the cylinder's orientation vector

	float t = dot_product(CP, cylinder->orientation) / dot_product(cylinder->orientation, cylinder->orientation);

	// Step 3: Calculate the point Q on the cylinder's axis
	t_vector Q = add_vector(cylinder_center, multiply_vector(cylinder->orientation, t));

	// Step 4: Calculate the normal vector as the vector from Q to the point
	t_vector N = sub_vector(point, Q);

	// Step 5: Normalize the normal vector
	normalize(&N);

	return N;
}
