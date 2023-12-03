#include "world.h"

t_light *new_light(t_vector origin, t_color color, double bright_ratio)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	light->origin = origin;
	light->color = color;
	light->bright_ratio = bright_ratio;
	light->next = NULL;
	return light;
}
