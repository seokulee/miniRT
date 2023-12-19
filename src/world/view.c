#include "world.h"

t_view new_view(t_vector position, t_vector direction, double fov)
{
    t_view view;

    view.position = position;
    view.direction = direction;
    view.fov = fov;
    return view;
}

static t_vector get_left_top(t_view *view, t_vector z_axis)
{
	t_vector left_top;

	left_top = v_subtract(view->position, v_multiple(z_axis, FOCAL_LENGTH));
	left_top = v_subtract(left_top, v_multiple(view->x_axis, view->n_width));
	left_top = v_add(left_top, v_multiple(view->y_axis, view->n_height));
	return left_top;
}

void set_view_size(int w_width, int w_height, t_view *view)
{
	t_vector z_axis;
	double aspect_ratio;

	view->direction = unit(view->direction);
	z_axis = reverse(view->direction);
	view->x_axis = v_cross(view->direction, new_vector(0, 1, 0));
	view->y_axis = v_cross(z_axis, view->x_axis);
	view->w_height = w_height;
	view->w_width = w_width;
	view->n_width = tan(view->fov * PI / 360.0) * FOCAL_LENGTH;
	aspect_ratio = (double)w_height / (double)w_width;
	view->n_height = view->n_width * aspect_ratio;
	view->left_top = get_left_top(view, z_axis);
}

t_vector dir_to_pixel(t_pixel pixel, t_view *view)
{
	double x_ratio;
	double y_ratio;
	t_vector direction;

	x_ratio = 2.0 * view->n_width * ((double)pixel.x / view->w_width);
	y_ratio = 2.0 * view->n_height * ((double)pixel.y / view->w_height);
	direction = v_add(view->left_top, v_multiple(view->x_axis, x_ratio));
	direction = v_subtract(direction, v_multiple(view->y_axis, y_ratio));
	direction = v_subtract(direction, view->position);
	return direction;
}
