#ifndef SHADING_H
# define SHADING_H

# include "world.h"

# define SPECULAR_EXPONENT 64
# define REFLECTION_COEFFICIENT 0.5

typedef struct s_phong_lighting
{
	t_color	color;
	t_color	ambient;
	t_color	diffuse_sum;
	t_color	specular_sum;
}	t_phong_lighting;

typedef struct s_direction
{
	t_vector	normal;
	t_vector	to_view;
	t_vector	to_light;
	t_vector	to_light_unit;
	t_vector	reflected;
}	t_direction;

t_phong_lighting	new_phong_lighting(t_color color, t_ambient *ambient);
t_direction			new_direction_vectors(t_ray *ray, t_hit_record *rec, \
															t_light *light);
void				diffuse(t_light *light, t_direction dir, \
												t_phong_lighting *phong);
void				specular(t_light *light, t_direction dir, \
												t_phong_lighting *phong);

#endif
