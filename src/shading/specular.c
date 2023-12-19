#include "shading.h"

void specular(t_light *light, t_direction dir, t_phong_lighting *phong)
{
	t_color existing_specular;
	t_color new_specular;
	double highlight;

	existing_specular = phong->specular_sum;
	highlight = pow(fmax(v_dot(dir.to_view, dir.reflected), 0.0), SPECULAR_EXPONENT);
	new_specular = multiply_ratio(light->color, REFLECTION_COEFFICIENT * highlight);
	phong->specular_sum = add_color(existing_specular, new_specular);
}
