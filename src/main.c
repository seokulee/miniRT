#include "minirt.h"

int main(int argc, char *argv[])
{
	t_world world;

	init_world(&world, argc, argv[1]);
	set_view_size(WIDTH, HEIGHT, &world.view);
	// world.view.fov = 90;
	// world.view.position = new_vector(0,0,0.2);
	// world.view.direction = new_vector(-0.5,0,-1);
	// world.ambient.color = new_color(1,1,1);
	// world.ambient.ratio = 0.1;
	// add_object(&world, test_sphere(new_vector(-2, 0, -5), 2, new_color(0.5, 0, 0)));
	// add_object(&world, test_sphere(new_vector(2, 0, -5), 2, new_color(0, 0.5, 0)));
	// // add_object(&world, test_cylinder(new_vector(0, -4, -10), new_vector(0,1,0), 3, 2, new_color(1,0,0)));
	// add_object(&world, test_plane(new_vector(0, -5, 0), new_vector(0,1,0), new_color(1,1,1)));
	// add_object(&world, test_plane(new_vector(0, 0, -1000), new_vector(0,0,1), new_color(1,1,1)));
	// add_light(&world, new_light(new_vector(-50, 50, -10), new_color(1, 1, 1), 0.5));
	// add_light(&world, new_light(new_vector(50, 50, -10), new_color(1, 1, 1), 0.5));

	rendering(&world);
}
