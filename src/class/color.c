#include "class.h"

t_color	new_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

t_color	get_color(t_ray *ray)
{
	t_color white = new_color(1, 1, 1);
	t_color	sky_blue = new_color(0.5, 0.7, 1);
	double	ratio = 0.5 * (ray->dir.y + 1.0);
	return new_color(
		white.r * (1.0 - ratio) + sky_blue.r * ratio,
		white.g * (1.0 - ratio) + sky_blue.g * ratio,
		white.b * (1.0 - ratio) + sky_blue.b * ratio
	);
}

int	convert_color(t_color color)
{
	int r = (int)(255.999 * color.r);
	int g = (int)(255.999 * color.g);
	int b = (int)(255.999 * color.b);
	return (r << 16 | g << 8 | b);
}
