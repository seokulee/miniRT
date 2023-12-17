#ifndef MINIRT_H
# define MINIRT_H

# include "world.h"
# include "parsing.h"

# define WIDTH 400
# define HEIGHT 300

void rendering(t_view *view, t_world *world);
t_color phong_lighting(t_ray *ray, t_world *world, t_hit_record *rec);

#endif
