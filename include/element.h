#ifndef ELEMENT_H
# define ELEMENT_H

#include <math.h>

/* ------------------------- boolean ------------------------- */
typedef int t_bool;

# define TRUE 1;
# define FALSE 0;

/* ------------------------- vector ------------------------- */
typedef struct s_vector
{
	double x;
	double y;
	double z;
} t_vector;

t_vector new_vector(double x, double y, double z);
t_vector add_vector(t_vector v1, t_vector v2);
t_vector subtract_vector(t_vector v1, t_vector v2);
t_vector multiply_scalar(t_vector vector, double scalar);
double dot_product(t_vector v1, t_vector v2);
t_vector unit(t_vector vector);
t_vector reverse(t_vector vector);
double length(t_vector vector);

/* ------------------------- pixel ------------------------- */
typedef struct s_pixel
{
	int x;
	int y;
} t_pixel;

t_pixel new_pixel(int x, int y);

/* ------------------------- ray ------------------------- */
typedef struct s_ray
{
	t_vector origin;
	t_vector dir; // direction
} t_ray;

t_ray new_ray(t_vector origin, t_vector direction);
t_vector get_point_on_ray(t_ray *ray, double t);

/* ------------------------- color ------------------------- */
typedef struct s_color
{
	double r;
	double g;
	double b;
} t_color;

t_color new_color(double r, double g, double b);
t_color multiply_ratio(t_color color, double ratio);
t_color multiply_color(t_color c1, t_color c2);
t_color add_color(t_color c1, t_color c2);

#endif
