#include "element.h"

t_ray new_ray(t_vector origin, t_vector direction)
{
	t_ray ray;

	ray.origin = origin;
	ray.dir = direction;
	return ray;
}

t_vector get_point_on_ray(t_ray *ray, double t)
{
	return v_add(ray->origin, v_multiple(ray->dir, t));
}
