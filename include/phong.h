#ifndef PHONG_H
#define PHONG_H

#include "world.h"

#define SPECULAR_EXPONENT 64
#define REFLECTION_COEFFICIENT 0.5

typedef struct s_direction
{
	t_vector normal;
	t_vector to_camera;
	t_vector to_light;
	t_vector n_to_light;
	t_vector reflected;
}	t_direction;

typedef struct s_phong
{
	t_color color;
	t_color ambient;
	t_color diffuse_sum;
	t_color specular_sum;
}	t_phong;

t_phong new_phong_model(t_color color, t_color ambient);
void diffuse(t_light *light, t_direction dir, t_phong *phong);
void specular(t_light *light, t_direction dir, t_phong *phong);
t_color calculate_color(t_phong *phong);

#endif
