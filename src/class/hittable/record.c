#include "hittable.h"

double root(t_discriminant d, double max)
{
	double root;

	root = (-d.half_b - d.sqrt_d) / d.a;
	if (root <= 0.0 || root >= max)
	{
		root = (-d.half_b + d.sqrt_d) / d.a;
	}
	return root;
}

t_bool is_hit(t_hit_record *rec, t_ray *ray, t_hittable *object)
{
	t_discriminant d;
	double t;

	d = sp_discriminant(ray, object);
	t = root(d, rec->t);
	if (d.is_negative)
		return FALSE;
	if (t <= 0.0 || t >= rec->t)
		return FALSE;
	rec->t = t;
	rec->is_hit = TRUE;
	return TRUE;
}

t_hit_record new_hit_record()
{
	t_hit_record rec;

	rec.t = INFINITY;
	rec.is_hit = FALSE;
	return rec;
}

void calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object)
{
	if (!is_hit(rec, ray, object))
		return;
	rec->normal = unit(subtract_vector(point_on_ray(ray, rec->t), object->center));
	rec->is_inside = FALSE;
	if (dot_product(ray->dir, rec->normal) > 0.0)
	{
		rec->normal = multiply_scalar(rec->normal, -1);
		rec->is_inside = TRUE;
	}
}
