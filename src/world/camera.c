#include "world.h"

t_camera new_camera(t_vector position, t_vector direction, double fov)
{
    t_camera camera;

    camera.position = position;
    camera.direction = direction;
    camera.fov = fov;
    return camera;
}
