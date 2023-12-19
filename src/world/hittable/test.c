#include "hittable.h"

t_hittable *test_sphere(t_vector center, double radius, t_color color)
{
	t_hittable *sphere;

	sphere = malloc(sizeof(t_hittable));
	sphere->type = SPHERE;
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	sphere->next = NULL;
	return sphere;
}

t_hittable *test_plane(t_vector position, t_vector normal, t_color color)
{
    t_hittable *plane;

    plane = malloc(sizeof(t_hittable));
    plane->type = PLANE;
    plane->center = position;
    plane->normal = unit(normal);
    plane->color = color;
    plane->radius = 0;
    plane->next = NULL;
    return plane;
}

t_hittable *test_cylinder(t_vector center, t_vector normal, double radius, double height, t_color color)
{
    t_hittable *cylinder;

    cylinder = malloc(sizeof(t_hittable));
    cylinder->type = CYLINDER;
    cylinder->center = center;
    cylinder->normal = unit(normal);
    cylinder->radius = radius;
    cylinder->height = height;
    cylinder->color = color;
    cylinder->next = NULL;
    return cylinder;
}
