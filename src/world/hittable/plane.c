#include "hittable.h"

t_bool is_plane_hit(t_hit_record *rec, t_ray *ray, t_hittable *pl)
{
	double t;
	double distance;
	t_vector hit_point;

	t = v_dot(v_subtract(pl->center, ray->origin), pl->normal);
	t /= v_dot(ray->dir, pl->normal);
	hit_point = get_point_on_ray(ray, t);
	distance = v_length(v_subtract(pl->center, hit_point));
	if (pl->radius > 0 && distance > pl->radius)
		return FALSE;
	if (!is_hit(rec, t))
		return FALSE;
	rec->hit_point = hit_point;
	return TRUE;
}

t_bool plane_hit(t_hit_record *rec, t_ray *ray, t_hittable *plane)
{
	if (!is_plane_hit(rec, ray, plane))
		return FALSE;
	rec->color = plane->color;
	rec->normal = plane->normal;
	if (is_inside_hit(ray, rec->normal))
		rec->normal = reverse(rec->normal);
	return TRUE;
}
