#include "hittable.h"

t_hittable new_sphere(t_vector center, double radius)
{
	t_hittable sphere;

	sphere.type = SPHERE;
	sphere.center = center;
	sphere.radius = radius;
	return sphere;
}

double root(t_ray *ray, t_hittable sphere)
{
	t_vector oc;
	double a;
	double half_b;
	double c;
	double discriminant;

	oc = subtract_vector(ray->origin, sphere.center);
	a = dot_product(ray->dir, ray->dir);
	half_b = dot_product(ray->dir, oc);
	c = dot_product(oc, oc) - sphere.radius * sphere.radius;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return -1;
	return (-half_b - sqrt(discriminant)) / a;
}
