#include "world.h"

void init_world(t_world *world)
{
	world->last_object = &world->first_dummy_object;
	world->last_light = &world->first_dummy_light;
	world->ambient.color = multiply_ratio(new_color(1, 1, 1), 0.1);
	world->cnt_ambient = 0;
	world->cnt_camera = 0;
	world->cnt_lights = 0;
	world->cnt_objects = 0;
}

void add_object(t_world *world, t_hittable *object)
{
	world->last_object->next = object;
	world->last_object = object;
}

void add_light(t_world *world, t_light *light)
{
	world->last_light->next = light;
	world->last_light = light;
}
