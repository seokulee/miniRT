#ifndef MINIRT_H
# define MINIRT_H

# include "world.h"

# define WIDTH 400
# define HEIGHT 300

void rendering(t_view *view, t_world *world);
t_color ray_tracing(t_ray *ray, t_world *world);

#endif
