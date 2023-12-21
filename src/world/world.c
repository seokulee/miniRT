#include "parsing.h"

void init_world(t_world *world, int argc, char *rt_file)
{
	if (argc != 2)
		return (err_put_str("ERR_ARGC", 1));
	world->first_dummy_object.next = NULL;
	world->first_dummy_light.next = NULL;
	world->last_object = &world->first_dummy_object;
	world->last_light = &world->first_dummy_light;
	world->cnt_ambient = 0;
	world->cnt_camera = 0;
	world->cnt_lights = 0;
	world->cnt_objects = 0;
	if (read_rt_file(world, rt_file) == -1)
		return (err_put_str("ERR_FILE", 1));
}

void add_object(t_world *world, t_hittable *object)
{
	if (!object)
		return;
	world->last_object->next = object;
	world->last_object = object;
}

void add_light(t_world *world, t_light *light)
{
	world->last_light->next = light;
	world->last_light = light;
}
