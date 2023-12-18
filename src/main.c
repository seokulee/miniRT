#include "minirt.h"

int main(int argc, char *argv[])
{
	t_world world;

	init_world(&world, argc, argv[1]);
	world.view.fov = 90;
	world.view.position = new_vector(0,0,0);
	world.ambient.color = new_color(1,1,1);
	world.ambient.ratio = 0.1;
	set_view_size(WIDTH, HEIGHT, &world.view);
	add_object(&world, new_sphere(new_vector(-2, 0, -5), 2, new_color(0.5, 0, 0)));
	add_object(&world, new_sphere(new_vector(2, 0, -5), 2, new_color(0, 0.5, 0)));
	add_object(&world, new_sphere(new_vector(0, -1000, 0), 990, new_color(1, 1, 1)));
	add_light(&world, new_light(new_vector(0, 5, 0), new_color(1, 1, 1), 0.5));

	rendering(&world);
}
