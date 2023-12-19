#include "hittable.h"

t_discriminant sphere_discriminant(t_ray *ray, t_hittable *sphere)
{
	t_discriminant d;
	t_vector oc;
	double c;
	double discriminant;

	oc = v_subtract(ray->origin, sphere->center);
	d.a = v_dot(ray->dir, ray->dir);
	d.half_b = v_dot(ray->dir, oc);
	c = v_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = d.half_b * d.half_b - d.a * c;
	d.is_negative = (discriminant < 0);
	d.sqrt_d = sqrt(discriminant);
	return d;
}

t_bool sphere_hit(t_hit_record *rec, t_ray *ray, t_hittable *sphere)
{
	t_discriminant d;

	d = sphere_discriminant(ray, sphere);
	if (!is_hit(rec, root(d, rec->t)))
		return FALSE;
	rec->color = sphere->color;
	rec->hit_point = get_point_on_ray(ray, rec->t);
	rec->normal = unit(v_subtract(rec->hit_point, sphere->center));
	if (is_inside_hit(ray, rec->normal))
		rec->normal = reverse(rec->normal);
	return TRUE;
}
