#include "world.h"

double degrees_to_radians(double degrees)
{
	return degrees * PI / 180.0;
}

t_view new_view(t_vector position, t_vector direction, double fov)
{
    t_view view;

    view.position = position;
    view.direction = direction;
    view.fov = fov;
    return view;
}

void set_view_size(int w_width, int w_height, t_view *view)
{
	double theta;
	double h;
	double aspect_ratio;
	double focal_length = 1.0;

	view->w_height = w_height;
	view->w_width = w_width;
	theta = degrees_to_radians(view->fov);
	h = tan(theta / 2);
	view->n_height = 2 * h * focal_length;
	aspect_ratio = (double)w_width / (double)w_height;
	view->n_width = view->n_height * aspect_ratio;
	view->left_top = subtract_vector(
		view->position,
		new_vector(view->n_width / 2, -view->n_height / 2, focal_length)
	);
}

t_vector dir_to_pixel(t_pixel pixel, t_view *view)
{
	double x;
	double y;

	x = view->n_width * ((double)pixel.x / view->w_width);
	y = -view->n_height * ((double)pixel.y / view->w_height);
	return add_vector(view->left_top, new_vector(x, y, 0));
}
