#include "hittable.h"

t_hittable *new_sphere(t_vector center, double diameter, t_color color)
{
	t_hittable *sphere;

	sphere = malloc(sizeof(t_hittable));
	sphere->type = SPHERE;
	sphere->center = center;
	sphere->radius = diameter / 2;
	sphere->color = color;
	sphere->next = NULL;
	return sphere;
}

t_discriminant sp_discriminant(t_ray *ray, t_hittable *sphere)
{
	t_discriminant d;
	t_vector oc;
	double c;
	double discriminant;

	oc = subtract_vector(ray->origin, sphere->center);
	d.a = dot_product(ray->dir, ray->dir);
	d.half_b = dot_product(ray->dir, oc);
	c = dot_product(oc, oc) - sphere->radius * sphere->radius;
	discriminant = d.half_b * d.half_b - d.a * c;
	d.is_negative = (discriminant < 0);
	d.sqrt_d = sqrt(discriminant);
	return d;
}
