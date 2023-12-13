#include "element.h"

t_color new_color(double r, double g, double b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return color;
}

t_color multiply_ratio(t_color color, double ratio)
{
	color.r *= ratio;
	color.g *= ratio;
	color.b *= ratio;
	return color;
}

t_color multiply_color(t_color c1, t_color c2)
{
	t_color color;

	color.r = c1.r * c2.r;
	color.g = c1.g * c2.g;
	color.b = c1.b * c2.b;
	return color;
}

t_color add_color(t_color c1, t_color c2)
{
	t_color color;

	color.r = c1.r + c2.r;
	color.g = c1.g + c2.g;
	color.b = c1.b + c2.b;
	return color;
}
