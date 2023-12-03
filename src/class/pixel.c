#include "class.h"

t_pixel	new_pixel(int x, int y)
{
	t_pixel	pixel;

	pixel.x = x;
	pixel.y = y;
	return pixel;
}

t_vector	pixel_to_vector(t_pixel pixel, t_view *view)
{
	t_vector	vector;

	vector.x = view->n_width * ((double)pixel.x / view->w_width);
	vector.y = -view->n_height * ((double)pixel.y / view->w_height);
	vector.z = 0;
	return vector;
}
