#include "../inc/constant.h"
#include "../inc/types.h"
#include "../inc/operation.h"

void	set_pixel_color(t_ray_tracing *raytracer, float brightness, color color)
{
	float cos;

	cos = get_cos(raytracer->hit_point_to_light, raytracer->normal);
	raytracer->color.t_rgba.alpha = 0;
	if (cos >= 1.0 - brightness)
	{
		// Full color
		raytracer->color.t_rgba.red = color.t_rgba.red;
		raytracer->color.t_rgba.green = color.t_rgba.green;
		raytracer->color.t_rgba.blue = color.t_rgba.blue;
	}
	else if (cos < 1.0 - brightness && cos >= GRADIENT_END) {
		// Calculate the brightness factor for the gradient from color to black
		float brightness_factor = (cos + (-1.0 * GRADIENT_END)) / (1.0 - brightness + (-1.0 * GRADIENT_END));

		// Apply the gradient
		raytracer->color.t_rgba.red = color.t_rgba.red * brightness_factor;
		raytracer->color.t_rgba.green = color.t_rgba.green * brightness_factor;
		raytracer->color.t_rgba.blue = color.t_rgba.blue * brightness_factor;
	}
	else if (cos < GRADIENT_END) {
		// Fully black
		raytracer->color.color = 0x00000000;
	}
}
