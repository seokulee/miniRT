#include "hittable.h"

t_hittable *new_cylinder(t_vector center, t_vector normal, double diameter, double height, t_color color)
{
    t_hittable *cylinder;

    cylinder = malloc(sizeof(t_hittable));
    cylinder->type = CYLINDER;
    cylinder->center = center;
    cylinder->normal = normal;
    cylinder->radius = diameter / 2;
    cylinder->height = height;
    cylinder->color = color;
    cylinder->next = NULL;
    return cylinder;
}
