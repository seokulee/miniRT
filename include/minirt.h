#ifndef MINIRT_H
# define MINIRT_H

# include "world.h"
# include "parsing.h"

# define WIDTH 1600
# define HEIGHT 1200

void	init_world(t_world *world, int argc, char *rt_file);
void	rendering(t_world *world);
t_color	phong_lighting(t_ray *ray, t_world *world, t_hit_record *rec);

#endif
