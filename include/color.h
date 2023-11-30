#ifndef COLOR_H
# define COLOR_H

# include "hittable.h"

typedef struct s_color
{
	double r;
	double g;
	double b;
} t_color;

t_color	get_color(t_ray *ray, t_hittable hittable);
int convert_color(t_color color);

#endif
