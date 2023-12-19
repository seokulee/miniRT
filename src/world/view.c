#include "world.h"

t_view new_view(t_vector position, t_vector direction, double fov)
{
    t_view view;

    view.position = position;
    view.direction = direction;
    view.fov = fov;
    return view;
}

double get_n_width(double fov)
{
	double theta;
	double w;

	theta = fov * PI / 180.0;
	w = tan(theta / 2.0);
	return (2.0 * w * FOCAL_LENGTH);
}

void set_view_size(int w_width, int w_height, t_view *view)
{
	t_vector x_axis;
	t_vector y_axis;
	t_vector z_axis;
	double aspect_ratio;

	z_axis = unit(reverse(view->direction));
	x_axis = unit(v_cross(view->direction, new_vector(0,1,0)));
	y_axis = v_cross(z_axis, x_axis);
	view->w_height = w_height;
	view->w_width = w_width;
	view->n_width = get_n_width(view->fov);
	aspect_ratio = (double)w_height / (double)w_width;
	view->n_height = view->n_width * aspect_ratio;
	view->left_top = v_subtract(view->position, v_multiply_scalar(z_axis, FOCAL_LENGTH));
	view->left_top = v_subtract(view->left_top, v_multiply_scalar(x_axis, view->n_width / 2));
	view->left_top = v_add(view->left_top, v_multiply_scalar(y_axis, view->n_height / 2));
}

t_vector dir_to_pixel(t_pixel pixel, t_view *view)
{
	double x;
	double y;

	x = view->n_width * ((double)pixel.x / view->w_width);
	y = -view->n_height * ((double)pixel.y / view->w_height);
	return v_add(view->left_top, new_vector(x, y, 0));
}
