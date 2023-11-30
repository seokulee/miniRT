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

/* util */
t_bool is_hit(t_ray *ray, t_hittable hittable);

/* constructor */
t_hittable new_sphere(t_vector center, double radius);

/* discriminant */
double sp_discriminant(t_ray *ray, t_hittable sphere);

#endif
