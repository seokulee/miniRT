#include "parsing.h"

void	get_ambient(t_world *world, char **tab)
{
    double  ratio;
    t_color color;

    ratio = ft_atof(tab[1]);
    color = get_color(tab[2]);
    world->ambient = new_ambient(color, ratio);
}

void	get_view(t_world *world, char **tab)
{
    t_vector    position;
    t_vector    direction;
    double      fov;

	position = get_vector(tab[1]);
	direction = get_vector(tab[2]);
	fov = ft_atof(tab[3]);
	world->view = new_view(position, direction, fov);
}

void	get_light(t_world *world, char **tab)
{
    t_vector    origin;
    double      bright_ratio;
    t_color     color;

	origin = get_vector(tab[1]);
	bright_ratio = ft_atof(tab[2]);
	color = get_color(tab[3]);
    add_light(world, new_light(origin, color, bright_ratio));
}

void	get_object(t_world *world, char **tab)
{
    t_hittable *object;

    object = NULL;
	if (ft_strcmp(tab[0], "sp") == 0)
        object = get_sphere(tab);
    else if (ft_strcmp(tab[0], "pl") == 0)
        object = get_plane(tab);
    else if (ft_strcmp(tab[0], "cy") == 0)
        object = get_cylinder(tab);
    add_object(world, object);
}
