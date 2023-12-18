#ifndef WORLD_H
# define WORLD_H

# include "hittable.h"

/* ------------------------- view ------------------------- */
typedef struct s_view
{
	int w_width;
	int w_height;
	double n_width;
	double n_height;
	t_vector camera;
	t_vector left_top;
} t_view;

t_view new_view(int w_width, int w_height, t_vector camera);
t_vector dir_to_pixel(t_pixel pixel, t_view *view);

/* ------------------------- light ------------------------- */
typedef struct s_light t_light;

struct s_light
{
    t_vector origin;
    t_color color;
    double bright_ratio;
    t_light *next;
};

t_light *new_light(t_vector origin, t_color color, double bright_ratio);

/* ------------------------- ambient ------------------------- */
typedef struct s_ambient t_ambient;

struct s_ambient
{
    t_color color;
    double ratio;
};

t_ambient new_ambient(t_color color, double ratio);

/* ------------------------- camera ------------------------- */
typedef struct s_camera t_camera;

struct s_camera
{
    t_vector position;
    t_vector direction;
    double fov;
};

t_camera new_camera(t_vector position, t_vector direction, double fov);

/* ------------------------- world ------------------------- */
typedef struct s_world
{
    t_hittable first_dummy_object;
    t_hittable *last_object;
    t_light first_dummy_light;
    t_light *last_light;
    t_ambient ambient;
    t_camera camera;
    size_t cnt_ambient;
    size_t cnt_camera;
    size_t cnt_lights;
    size_t cnt_objects;
} t_world;

void init_world(t_world *world);
void add_object(t_world *world, t_hittable *object);
void add_light(t_world *world, t_light *light);

#endif
