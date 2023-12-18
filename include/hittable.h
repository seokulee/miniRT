#ifndef HITTABLE_H
# define HITTABLE_H

# include "element.h"
# include <stdlib.h>

# define EPSILON 1e-6
# define PI 3.14159265359

typedef struct s_discriminant
{
    double a;
    double half_b;
    t_bool is_negative;
    double sqrt_d;
} t_discriminant;

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

/* sphere */
t_hittable *new_sphere(t_vector center, double radius, t_color color);
t_discriminant sp_discriminant(t_ray *ray, t_hittable *sphere);

/* ------------------------- hit record ------------------------- */
typedef struct s_hit_record
{
    double t;
    double tmin;
    t_bool is_hit;
    t_color color;
    t_vector hit_point;
    t_vector normal;
    t_bool is_inside;
} t_hit_record;

t_hit_record new_hit_record(double max, double min);
t_bool calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);

#endif
