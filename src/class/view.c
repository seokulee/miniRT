#include "class.h"

t_view new_view(double w_width, double w_height, t_vector camera)
{
	t_view view;
	double aspect_ratio;
	double focal_length = 1.0;

	view.w_height = w_height;
	view.w_width = w_width;
	view.n_height = 2.0;
	aspect_ratio = (double)w_width / (double)w_height;
	view.n_width = view.n_height * aspect_ratio;
	view.camera = camera;
	view.left_top_from_cam = subtract_vector(
		camera,
		new_vector(view.n_width / 2, -view.n_height / 2, focal_length)
	);
	return view;
}