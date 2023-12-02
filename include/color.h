#ifndef COLOR_H
# define COLOR_H

# include "hittable.h"

typedef struct s_color
{
	double r;
	double g;
	double b;
} t_color;

t_color calc_color(t_ray *ray, t_hittable_list *world);
int convert_color(t_color color);

#endif
