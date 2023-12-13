#include "shading.h"

t_phong_lighting new_phong_lighting(t_color color, t_color ambient)
{
	t_phong_lighting phong;

	phong.color = color;
	phong.ambient = ambient;
	phong.diffuse_sum = new_color(0, 0, 0);
	phong.specular_sum = new_color(0, 0, 0);
	return phong;
}

t_direction new_direction_vectors(t_ray *ray, t_hit_record *rec, t_light *light)
{
	t_direction dir;

	dir.normal = rec->normal;
	dir.to_camera = reverse(unit(ray->dir));
	dir.to_light = subtract_vector(light->origin, rec->hit_point);
	dir.to_light_unit = unit(dir.to_light);
	dir.reflected = subtract_vector(
		multiply_scalar(dir.normal, dot_product(dir.to_light_unit, dir.normal) * 2),
		dir.to_light_unit);
	return dir;
}
