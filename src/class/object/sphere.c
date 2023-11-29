#include "object.h"

t_object new_sphere(t_vector center, double radius)
{
	t_object sphere;

	sphere.type = SPHERE;
	sphere.center = center;
	sphere.radius = radius;
	return sphere;
}

double sp_discriminant(t_ray *ray, t_object sphere)
{
	double a;
	double b;
	double c;
	t_vector center_to_ray;

	center_to_ray = subtract_vector(ray->pos, sphere.center);
	a = dot_product(ray->dir, ray->dir);
	b = dot_product(multiply_scalar(ray->dir, 2), center_to_ray);
	c = dot_product(center_to_ray, center_to_ray) - sphere.radius * sphere.radius;
	return (b * b - 4 * a * c);
}
