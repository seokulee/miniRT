#include "shading.h"

t_phong_lighting new_phong_lighting(t_color color, t_ambient *ambient)
{
	t_phong_lighting phong;

	phong.color = color;
	phong.ambient = multiply_ratio(ambient->color, ambient->ratio);
	phong.diffuse_sum = new_color(0, 0, 0);
	phong.specular_sum = new_color(0, 0, 0);
	return phong;
}

t_direction new_direction_vectors(t_ray *ray, t_hit_record *rec, t_light *light)
{
	t_direction dir;

	dir.normal = rec->normal;
	dir.to_view = reverse(unit(ray->dir));
	dir.to_light = v_subtract(light->origin, rec->hit_point);
	dir.to_light_unit = unit(dir.to_light);
	dir.reflected = v_subtract(
		v_multiple(dir.normal, v_dot(dir.to_light_unit, dir.normal) * 2),
		dir.to_light_unit);
	return dir;
}
