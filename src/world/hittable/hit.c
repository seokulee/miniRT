#include "hittable.h"

double root(t_discriminant d, double max)
{
	double root;

	if (d.is_negative)
		return -1.0;
	root = (-d.half_b - d.sqrt_d) / d.a;
	if (root <= EPSILON || root >= max)
	{
		root = (-d.half_b + d.sqrt_d) / d.a;
	}
	return root;
}

t_bool is_hit(t_hit_record *rec, double t)
{
	if (t <= rec->tmin || t >= rec->t)
		return FALSE;
	rec->t = t;
	rec->is_hit = TRUE;
	return TRUE;
}

t_bool is_inside_hit(t_ray *ray, t_vector normal)
{
	return (v_dot(ray->dir, normal) > 0.0);
}

t_hit_record new_hit_record(double max, double min)
{
	t_hit_record rec;

	rec.t = max;
	rec.tmin = min;
	rec.is_hit = FALSE;
	return rec;
}

t_bool calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object)
{
	if (object->type == SPHERE)
		return sphere_hit(rec, ray, object);
	if (object->type == PLANE)
		return plane_hit(rec, ray, object);
	if (object->type == CYLINDER)
		return cylinder_hit(rec, ray, object);
	return FALSE;
}
