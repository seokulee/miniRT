#ifndef PARSING_H
# define PARSING_H

# include "world.h"

int read_rt_file(t_world *world, char *open_file);

/* get by id */
void	get_ambient(t_world *world, char **tab);
void	get_camera(t_world *world, char **tab);
void	get_light(t_world *world, char **tab);
void	get_object(t_world *world, char **tab);

/* get functions */
double	ft_atof(char *str);
t_color get_rgb(const char *rgb_string);
t_vector	get_vector(const char *vec_string);

#endif
