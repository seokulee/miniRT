#include "hittable.h"

double root(t_discriminant d, double max)
{
	double root;

	root = (-d.half_b - d.sqrt_d) / d.a;
	if (root <= EPSILON || root >= max)
	{
		root = (-d.half_b + d.sqrt_d) / d.a;
	}
	return root;
}

t_bool is_hit(t_hit_record *rec, t_discriminant d)
{
	double t;

	t = root(d, rec->t);
	if (d.is_negative)
		return FALSE;
	if (t <= rec->tmin || t >= rec->t)
		return FALSE;
	rec->t = t;
	rec->is_hit = TRUE;
	return TRUE;
}

t_hit_record new_hit_record(double max, double min)
{
	t_hit_record rec;

	rec.t = max;
	rec.tmin = min;
	rec.is_hit = FALSE;
	return rec;
}

t_bool sp_hit(t_hit_record *rec, t_ray *ray, t_hittable *object)
{
	t_discriminant d;

	d = sp_discriminant(ray, object);
	if (!is_hit(rec, d))
		return FALSE;
	rec->color = object->color;
	rec->hit_point = get_point_on_ray(ray, rec->t);
	rec->normal = unit(subtract_vector(rec->hit_point, object->center));
	rec->is_inside = FALSE;
	if (dot_product(ray->dir, rec->normal) > 0.0)
	{
		rec->normal = reverse(rec->normal);
		rec->is_inside = TRUE;
	}
	return TRUE;
}

t_bool calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object)
{
	if (object->type == SPHERE)
		return sp_hit(rec, ray, object);
	return FALSE;
}
