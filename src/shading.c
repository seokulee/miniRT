#include "world.h"

t_color diffuse(t_light *light, t_hit_record *rec)
{
	t_vector dv_to_light;
	double diffuse;

	dv_to_light = unit(subtract_vector(light->origin, rec->intersection));
	diffuse = fmax(dot_product(dv_to_light, rec->normal), 0.0);
	return multiply_ratio(light->color, diffuse);
}

t_color specular(t_light *light, t_hit_record *rec, t_vector dv_to_view)
{
	t_vector dv_to_light;
	t_vector dv_reflected;

	dv_to_light = unit(subtract_vector(light->origin, rec->intersection));
	dv_reflected = subtract_vector(
		multiply_scalar(rec->normal, dot_product(dv_to_light, rec->normal) * 2),
		dv_to_light);
	double shininess_of_highlight = 64;
	double specular_strength = 0.5;
	double specular = pow(fmax(dot_product(dv_to_view, dv_reflected), 0.0), shininess_of_highlight);
	return multiply_ratio(light->color, specular_strength * specular);
}

t_color phong_lighting(t_world *world, t_hit_record *rec, t_vector dv_to_view)
{
	t_color diffuse_sum;
	t_color specular_sum;
	t_color color;
	t_light *light;

	diffuse_sum = new_color(0, 0, 0);
	specular_sum = new_color(0, 0, 0);
	light = world->first_dummy_light.next;
	while (light)
	{
		diffuse_sum = add_color(diffuse_sum, diffuse(light, rec));
		diffuse_sum = add_color(diffuse_sum, specular(light, rec, dv_to_view));
		light = light->next;
	}
	color = add_color(diffuse_sum, specular_sum);
	color = add_color(color, world->ambient);
	color = multiply_color(color, rec->color);
	return color;
}

t_color ray_tracing(t_ray *ray, t_world *world)
{
	t_hit_record rec;
	t_hittable *object;

	rec = new_hit_record();
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
