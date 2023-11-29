#include "class.h"

t_ray	ray_from_camera(t_pixel pixel, t_view view)
{
	t_ray	ray;

	ray.pos = view.camera;
	ray.dir = add_vector(view.left_top_from_cam, pixel_to_vector(pixel, view));
	return ray;
}
