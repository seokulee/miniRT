#include "shading.h"

void diffuse(t_light *light, t_direction dir, t_phong_lighting *phong)
{
	t_color existing_diffuse;
	t_color new_diffuse;
	double diffuse_ratio;

	existing_diffuse = phong->diffuse_sum;
	diffuse_ratio = fmax(v_dot(dir.to_light_unit, dir.normal), 0.0);
	new_diffuse = multiply_ratio(light->color, diffuse_ratio);
	phong->diffuse_sum = add_color(existing_diffuse, new_diffuse);
}
