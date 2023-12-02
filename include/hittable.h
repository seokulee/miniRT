#ifndef HITTABLE_H
# define HITTABLE_H

# include "class.h"
# include <stdlib.h>

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
} t_type;

typedef struct s_hittable t_hittable;

struct s_hittable
{
    t_type type;
    t_vector center;
    double radius;
    t_hittable *next;
};

/* sphere */
t_hittable *new_sphere(t_vector center, double radius);
t_discriminant sp_discriminant(t_ray *ray, t_hittable *sphere);

/* ------------------------- hittable list ------------------------- */
typedef struct s_hittable_list
{
    t_hittable dummy_first;
    t_hittable *last;
} t_hittable_list;

void init_list(t_hittable_list *list);
void add_object(t_hittable_list *list, t_hittable *hittable);

/* ------------------------- hit record ------------------------- */
typedef struct s_hit_record
{
    double t;
    t_bool is_hit;
    t_vector normal;
    t_bool is_inside;
} t_hit_record;

t_hit_record new_hit_record();
void calculate_hit(t_hit_record *rec, t_ray *ray, t_hittable *object);

#endif
