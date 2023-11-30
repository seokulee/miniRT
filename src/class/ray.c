#include "class.h"

t_ray	ray_from_camera(t_pixel pixel, t_view view)
{
	t_ray	ray;

	ray.origin = view.camera;
	ray.dir = add_vector(view.left_top_from_cam, pixel_to_vector(pixel, view));
	return ray;
}

t_vector	point_on_ray(t_ray *ray, double t)
{
	return add_vector(ray->origin, multiply_scalar(ray->dir, t));
}
