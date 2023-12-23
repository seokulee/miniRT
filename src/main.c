#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_world	world;

	init_world(&world, argc, argv[1]);
	set_view_size(WIDTH, HEIGHT, &world.view);
	rendering(&world);
}
