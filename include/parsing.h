#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include "world.h"
# include "utils.h"
# include "error.h"

int read_rt_file(t_world *world, char *open_file);

/* get by id */
int     get_by_id(t_world *world, char **tab);
void	get_ambient(t_world *world, char **tab);
void	get_view(t_world *world, char **tab);
void	get_light(t_world *world, char **tab);
void	get_object(t_world *world, char **tab);

/* get object */
t_hittable *get_sphere(char **tab);
t_hittable *get_plane(char **tab);
t_hittable *get_cylinder(char **tab);

/* get functions */
double	ft_atof(char *str);
t_color get_color(const char *rgb_string);
t_vector	get_vector(const char *vec_string);

#endif
