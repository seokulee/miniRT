#include "phong.h"

t_direction direction_vectors(t_hit_record *rec, t_light *light, t_vector dir_to_camera)
{
	t_direction dir;

	dir.normal = rec->normal;
	dir.to_camera = dir_to_camera;
	dir.to_light = subtract_vector(light->origin, rec->hit_point);
	dir.n_to_light = unit(dir.to_light);
	dir.reflected = subtract_vector(
		multiply_scalar(dir.normal, dot_product(dir.n_to_light, dir.normal) * 2),
		dir.n_to_light);
	return dir;
}

t_ray hit_point_to_light(t_vector hit_point, t_direction dir)
{
	t_ray ray;

	ray.origin = add_vector(hit_point, multiply_scalar(dir.normal, EPSILON));
	ray.dir = dir.n_to_light;
	return ray;
}

t_bool in_shadow(t_world *world, t_direction dir, t_vector hit_point)
{
	t_hit_record rec;
	t_hittable *object;
	t_ray ray_to_light;

	rec = new_hit_record(length(dir.to_light), 0);
	ray_to_light = hit_point_to_light(hit_point, dir);
	object = world->first_dummy_object.next;
	while (object)
	{
		if (calculate_hit(&rec, &ray_to_light, object))
			return TRUE;
		object = object->next;
	}
	return FALSE;
}

t_color phong_lighting(t_world *world, t_hit_record *rec, t_vector dir_to_camera)
{
	t_phong phong;
	t_direction dir;
	t_light *light;

	phong = new_phong_model(rec->color, world->ambient);
	light = world->first_dummy_light.next;
	while (light)
	{
		dir = direction_vectors(rec, light, dir_to_camera);
		if (!in_shadow(world, dir, rec->hit_point))
		{
			diffuse(light, dir, &phong);
			specular(light, dir, &phong);
		}
		light = light->next;
	}
	return calculate_color(&phong);
}

t_color ray_tracing(t_ray *ray, t_world *world)
{
	t_hit_record rec;
	t_hittable *object;

	rec = new_hit_record(INFINITY, EPSILON);
	object = world->first_dummy_object.next;
	while (object)
	{
		calculate_hit(&rec, ray, object);
		object = object->next;
	}

	if (rec.is_hit)
		return phong_lighting(world, &rec, reverse(unit(ray->dir)));

	t_color white = new_color(1, 1, 1);
	t_color sky_blue = new_color(0.5, 0.7, 1);
	double ratio = 0.5 * (ray->dir.y + 1.0);
	return new_color(
		white.r * (1.0 - ratio) + sky_blue.r * ratio,
		white.g * (1.0 - ratio) + sky_blue.g * ratio,
		white.b * (1.0 - ratio) + sky_blue.b * ratio);
}
