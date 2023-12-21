#include "parsing.h"

t_color get_color(const char *rgb_string)
{
	char	*token;
	char	*tmp;
    double     r;
    double     g;
    double     b;

	tmp = ft_strdup(rgb_string);
	token = ft_strtok(tmp, ",");
	r = (double)ft_atof(token) / 255.0;
	token = ft_strtok(NULL, ",");
	g = (double)ft_atof(token) / 255.0;
	token = ft_strtok(NULL, ",");
	b = (double)ft_atof(token) / 255.0;
	free(tmp);
    /* rgb valid check fucntion */
	return (new_color(r, g, b));
}

t_vector	get_vector(const char *vec_string)
{
	char	*token;
	char	*tmp;
    double  x;
    double  y;
    double  z;

	tmp = ft_strdup(vec_string);
	token = ft_strtok(tmp, ",");
	x = ft_atof(token);
	token = ft_strtok(NULL, ",");
	y = ft_atof(token);
	token = ft_strtok(NULL, ",");
    z = ft_atof(token);
	free(tmp);
	return (new_vector(x, y, z));
}
