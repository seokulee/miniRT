#ifndef HITTABLE_H
# define HITTABLE_H

# include "class.h"

typedef enum e_type
{
    SPHERE,
} t_type;

typedef struct s_hittable
{
    t_type type;
    t_vector center;
    double radius;
} t_hittable;

/* sphere */
t_hittable new_sphere(t_vector center, double radius);
double root(t_ray *ray, t_hittable sphere);

/* ------------------------- hit record ------------------------- */
typedef struct s_hit_record
{
    double t;
    t_bool is_hit;
    t_vector normal;
} t_hit_record;

t_hit_record new_hit_record(t_ray *ray, t_hittable hittable);

#endif
