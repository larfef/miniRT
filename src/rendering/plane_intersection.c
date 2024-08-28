#include "../../inc/operation.h"
#include "../../inc/constant.h"
#include <math.h>
#include <stdio.h>

// float   plane_linear_equation(t_point *normal, t_point *origin, t_point *direction)
// {
//     float   solution;
//     float   denominator;
//     float   numerator;
//     float   D;
//
//     D = dot_product((t_vector){{0,0,0},*normal}, (t_vector){{0,0,0}, *direction});
//     numerator = (-1 * ((normal->x * origin->x)
//                 + (normal->y * origin->y)
//                 + (normal->z * origin->z))
//                 + D);
//     denominator = ((normal->x * direction->x)
//                     + (normal->y * direction->y)
//                     + (normal->z * direction->z));
//     if (denominator == 0)
//         return (-1.0f);
//     solution = numerator / denominator;
//     printf("numerator %f denominator %f solution %f \n", numerator, denominator, solution);
//     if (solution > 0 )
//         return (solution);
//     return (-1.0f);
// }

float plane_linear_equation(t_point *normal, t_point *origin, t_point *direction)
{
    float solution;
    float denominator;
    float numerator;

    // Denominator is the dot product of the plane normal and ray direction
    denominator = dot_product((t_vector){{0,0,0},*normal}, (t_vector){{0,0,0}, *direction});

    // Check if ray is parallel to the plane (dot product close to zero)
    if (fabs(denominator) < EPSILON)
        return (-1.0f);

    // Calculate the numerator correctly
    numerator = -dot_product((t_vector){{0,0,0}, *normal}, (t_vector){{0,0,0}, *origin});

    // Calculate t, the scalar for the ray equation
    solution = numerator / denominator;

    // printf("numerator %f denominator %f solution %f \n", numerator, denominator, solution);

    // Return the solution only if it's positive, meaning the intersection is in front of the ray's origin
    if (solution >= 0)
        return (solution);

    return (-1.0f);
}



#include <stdio.h>
float    plane_intersection(t_shapes *plane, t_vector *hit_point)
{
    float   ret;

    ret = plane_linear_equation(&plane->orientation.dir, &hit_point->origin, &hit_point->dir);
    // printf("ret: %f\n", ret);
    return (ret);
}