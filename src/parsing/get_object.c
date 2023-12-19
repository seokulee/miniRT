#include "parsing.h"

t_hittable *get_sphere(char **tab)
{
	t_hittable *sphere;

	sphere = malloc(sizeof(t_hittable));
	sphere->type = SPHERE;
	sphere->center = get_vector(tab[1]);
    sphere->radius = ft_atof(tab[2]) / 2;
    sphere->color = get_color(tab[3]);
	sphere->next = NULL;
	return sphere;
}

t_hittable *get_plane(char **tab)
{
    t_hittable *plane;

    plane = malloc(sizeof(t_hittable));
    plane->type = PLANE;
	plane->center = get_vector(tab[1]);
	plane->normal = unit(get_vector(tab[2]));
	plane->color = get_color(tab[3]);
	plane->radius = 0;
    plane->next = NULL;
    return plane;
}

t_hittable *get_cylinder(char **tab)
{
    t_hittable *cylinder;

    cylinder = malloc(sizeof(t_hittable));
    cylinder->type = CYLINDER;
	cylinder->center = get_vector(tab[1]);
	cylinder->normal = unit(get_vector(tab[2]));
	cylinder->radius = ft_atof(tab[3]) / 2.0;
	cylinder->height = ft_atof(tab[4]);
	cylinder->color = get_color(tab[5]);
    cylinder->next = NULL;
    return cylinder;
}
