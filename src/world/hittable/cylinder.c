#include "hittable.h"

t_discriminant cylinder_discriminant(t_ray *ray, t_hittable *cy)
{
	t_discriminant d;
	t_vector oc;
	double c;
	double discriminant;

	d.a = v_power(v_cross(ray->dir, cy->normal));
	oc = v_subtract(ray->origin, cy->center);
	d.half_b = v_dot(v_cross(ray->dir, cy->normal), v_cross(oc, cy->normal));
	c = v_power(v_cross(oc, cy->normal)) - cy->radius * cy->radius;
	discriminant = d.half_b * d.half_b - d.a * c;
	d.is_negative = (discriminant < 0);
	d.sqrt_d = sqrt(discriminant);
	return d;
}

static t_vector get_normal(t_hit_record *rec, t_hittable *cy)
{
	t_vector center;

	center = v_add(cy->center, v_multiple(cy->normal, rec->height));
	return unit(v_subtract(rec->hit_point, center));
}

static t_bool is_side_hit(t_hit_record *rec, t_ray *ray, t_hittable *cy)
{
	t_discriminant d;
	double t;
	t_vector hit_point;

	d = cylinder_discriminant(ray, cy);
	t = root(d, rec->t);
	hit_point = get_point_on_ray(ray, t);
	rec->height = v_dot(v_subtract(hit_point, cy->center), cy->normal);
	if (fabs(rec->height) > cy->height / 2.0)
		return FALSE;
	if (!is_hit(rec, t))
		return FALSE;
	rec->hit_point = hit_point;
	return TRUE;
}

static t_hittable new_cylinder_cap(t_hittable *cy, t_bool is_top)
{
	t_hittable cap;
	t_vector height;

	cap.type = PLANE;
    cap.normal = cy->normal;
	if (!is_top)
		cap.normal = reverse(cy->normal);
	height = v_multiple(cap.normal, cy->height / 2.0);
    cap.center = v_add(cy->center, height);
    cap.color = cy->color;
    cap.radius = cy->radius;
    cap.next = NULL;
	return cap;
}

t_bool cylinder_hit(t_hit_record *rec, t_ray *ray, t_hittable *cy)
{
	t_hittable cap;

	cap = new_cylinder_cap(cy, TOP);
	plane_hit(rec, ray, &cap);
	cap = new_cylinder_cap(cy, BOTTOM);
	plane_hit(rec, ray, &cap);
	if (!is_side_hit(rec, ray, cy))
		return FALSE;
	rec->color = cy->color;
	rec->normal = get_normal(rec, cy);
	if (is_inside_hit(ray, rec->normal))
		rec->normal = reverse(rec->normal);
	return TRUE;
}
