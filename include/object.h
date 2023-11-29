#ifndef OBJECT_H
# define OBJECT_H

# include "class.h"

typedef enum e_type
{
    SPHERE,
}   t_type;

typedef struct s_object
{
    t_type  type;
    t_vector center;
    double  radius;
}   t_object;

/* util */
t_bool is_hit(t_ray *ray, t_object object);

/* constructor */
t_object new_sphere(t_vector center, double radius);

/* discriminant */
double sp_discriminant(t_ray *ray, t_object sphere);

#endif
