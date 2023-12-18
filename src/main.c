#include "minirt.h"

int main(int argc, char *argv[])
{
	t_view view;
	t_world world;

	if (argc != 2)
		return (err_put_str("ERR_ARGC", 1));
	init_world(&world);
	if (read_rt_file(&world, argv[1]) == -1)
		return (err_put_str("ERR_FILE", 1));
	view = new_view(WIDTH, HEIGHT, world.camera.position); // camera position : (0, 0, 0)
	add_object(&world, new_sphere(new_vector(-2, 0, -5), 2, new_color(0.5, 0, 0)));
	add_object(&world, new_sphere(new_vector(2, 0, -5), 2, new_color(0, 0.5, 0)));
	add_object(&world, new_sphere(new_vector(0, -1000, 0), 990, new_color(1, 1, 1)));
	add_light(&world, new_light(new_vector(0, 5, 0), new_color(1, 1, 1), 0.5));

	rendering(&view, &world);
}
