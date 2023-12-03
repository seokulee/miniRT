#include "minirt.h"

int main(void)
{
	t_view view;
	t_world world;

	view = new_view(WIDTH, HEIGHT, new_vector(0, 0, 0)); // camera position : (0, 0, 0)
	init_world(&world);
	add_object(&world, new_sphere(new_vector(-2, 0, -5), 2, new_color(0.5, 0, 0)));
	add_object(&world, new_sphere(new_vector(2, 0, -5), 2, new_color(0, 0.5, 0)));
	add_object(&world, new_sphere(new_vector(0, -1000, 0), 990, new_color(1, 1, 1)));
	add_light(&world, new_light(new_vector(0, 5, 0), new_color(1, 1, 1), 0.5));

	rendering(&view, &world);
}
