#include "../../inc/window_management.h"
#include "../../inc/operation.h"

void	set_viewport_vectors(float (*viewport)[2], t_vector (*viewport_vectors)[2], t_vector *w)
{
	t_vector	vup;
	t_vector	u;
	t_vector	minus_v;

	vup = get_vup(w);
	u = cross_product(vup, *w);
	normalize(&u);
	minus_v = cross_product(*w, u);
	minus_v = multiply_vector(minus_v, -1);
	//not really usefull
	normalize(&minus_v);
	(*viewport_vectors)[U] = multiply_vector(u, (*viewport)[WIDTH]);
	(*viewport_vectors)[V] = multiply_vector(minus_v, (*viewport)[HEIGHT]);
}
