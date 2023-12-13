#include "phong.h"

t_phong new_phong_model(t_color color, t_color ambient)
{
	t_phong phong;

	phong.color = color;
	phong.ambient = ambient;
	phong.diffuse_sum = new_color(0, 0, 0);
	phong.specular_sum = new_color(0, 0, 0);
	return phong;
}

void diffuse(t_light *light, t_direction dir, t_phong *phong)
{
	t_color existing_diffuse;
	t_color new_diffuse;
	double diffuse_ratio;

	existing_diffuse = phong->diffuse_sum;
	diffuse_ratio = fmax(dot_product(dir.n_to_light, dir.normal), 0.0);
	new_diffuse = multiply_ratio(light->color, diffuse_ratio);
	phong->diffuse_sum = add_color(existing_diffuse, new_diffuse);
}

void specular(t_light *light, t_direction dir, t_phong *phong)
{
	t_color existing_specular;
	t_color new_specular;
	double highlight;

	existing_specular = phong->specular_sum;
	highlight = pow(fmax(dot_product(dir.to_camera, dir.reflected), 0.0), SPECULAR_EXPONENT);
	new_specular = multiply_ratio(light->color, REFLECTION_COEFFICIENT * highlight);
	phong->specular_sum = add_color(existing_specular, new_specular);
}

t_color calculate_color(t_phong *phong)
{
	t_color lighting;

	lighting = add_color(phong->diffuse_sum, phong->specular_sum);
	lighting = add_color(lighting, phong->ambient);
	return multiply_color(phong->color, lighting);
}
