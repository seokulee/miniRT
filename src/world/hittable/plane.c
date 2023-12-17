#include "hittable.h"

t_hittable *new_plane(t_vector position, t_vector normal, t_color color)
{
    t_hittable *plane;

    plane = malloc(sizeof(t_hittable));
    plane->type = PLANE;
    plane->center = position;
    plane->normal = normal;
    plane->color = color;
    plane->next = NULL;
    return plane;
}
