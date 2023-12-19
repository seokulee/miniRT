#include "shading.h"

t_ray ray_to_light(t_vector hit_point, t_direction dir)
{
	t_vector calibrated;

	calibrated = v_add(hit_point, v_multiple(dir.normal, EPSILON));
	return new_ray(calibrated, dir.to_light_unit);
}

t_bool in_shadow(t_world *world, t_direction dir, t_vector hit_point)
{
	t_hit_record rec;
	t_hittable *object;
	t_ray ray;

	rec = new_hit_record(v_length(dir.to_light), 0);
	ray = ray_to_light(hit_point, dir);
	object = world->first_dummy_object.next;
	while (object)
	{
		if (calculate_hit(&rec, &ray, object))
			return TRUE;
		object = object->next;
	}
	return FALSE;
}

t_color calculate_color(t_phong_lighting *phong)
{
	t_color lighting;

	lighting = add_color(phong->diffuse_sum, phong->specular_sum);
	lighting = add_color(lighting, phong->ambient);
	return multiply_color(phong->color, lighting);
}

t_color phong_lighting(t_ray *ray, t_world *world, t_hit_record *rec)
{
	t_phong_lighting phong;
	t_direction dir;
	t_light *light;

	phong = new_phong_lighting(rec->color, &world->ambient);
	light = world->first_dummy_light.next;
	while (light)
	{
		dir = new_direction_vectors(ray, rec, light);
		if (!in_shadow(world, dir, rec->hit_point))
		{
			diffuse(light, dir, &phong);
			specular(light, dir, &phong);
		}
		light = light->next;
	}
	return calculate_color(&phong);
}
