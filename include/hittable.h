#ifndef HITTABLE_H
# define HITTABLE_H

# include "element.h"
# include <stdlib.h>

# define EPSILON 1e-6
# define PI 3.14159265359

# define TOP 1
# define BOTTOM 0

/* ------------------------- object ------------------------- */
typedef enum e_type
{
    SPHERE,
    PLANE,
    CYLINDER,
} t_type;

typedef struct s_hittable t_hittable;

struct s_hittable
{
    t_type type;
    t_vector center;
    double radius;
    double height;
    t_vector normal;
    t_color color;
    t_hittable *next;
};

t_hittable *test_sphere(t_vector center, double radius, t_color color);
t_hittable *test_plane(t_vector position, t_vector normal, t_color color);
t_hittable *test_cylinder(t_vector center, t_vector normal, double radius, double height, t_color color);

/* ------------------------- hit record ------------------------- */
typedef struct s_hit_record
{
    double t;
    double tmin;
    double height;
    t_bool is_hit;
    t_color color;
    t_vector hit_point;
    t_vector normal;
} t_hit_record;

t_hit_record new_hit_record(double max, double min);
t_bool calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);
t_bool sphere_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);
t_bool plane_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);
t_bool cylinder_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);
t_bool is_hit(t_hit_record *rec, double t);
t_bool is_inside_hit(t_ray *ray, t_vector normal);

/* ------------------------- operation ------------------------- */
typedef struct s_discriminant
{
    double a;
    double half_b;
    t_bool is_negative;
    double sqrt_d;
} t_discriminant;

double root(t_discriminant d, double max);

#endif
