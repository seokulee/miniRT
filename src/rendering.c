#include "minilibx.h"
#include "minirt.h"

static int convert_hex(double color_ratio)
{
	color_ratio = fmin(color_ratio, 1.0);
	return (int)(255.999 * color_ratio);
}

void color_pixel(t_mlx *mlx, t_pixel pixel, t_color color)
{
	char *dst;
	int converted_color;

	converted_color = convert_hex(color.r);
	converted_color <<= 8;
	converted_color += convert_hex(color.g);
	converted_color <<= 8;
	converted_color += convert_hex(color.b);
	dst = mlx->addr + (pixel.y * mlx->line_size + pixel.x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = converted_color;
}

t_color ray_tracing(t_ray *ray, t_world *world)
{
	t_hit_record rec;
	t_hittable *object;

	rec = new_hit_record(INFINITY, EPSILON);
	object = world->first_dummy_object.next;
	while (object)
	{
		calculate_hit(&rec, ray, object);
		object = object->next;
	}

	if (rec.is_hit)
		return phong_lighting(ray, world, &rec);
	return new_color(0, 0, 0);
}

void rendering(t_world *world)
{
	t_mlx mlx;

	mlx = new_mlx(world->view.w_width, world->view.w_height);
	int j = 0;
	while (j < world->view.w_height)
	{
		int i = 0;
		while (i < world->view.w_width)
		{
			t_pixel pixel = new_pixel(i, j);
			t_ray ray = new_ray(world->view.position, dir_to_pixel(pixel, &world->view));
			color_pixel(&mlx, pixel, ray_tracing(&ray, world));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hooks(&mlx);
	mlx_loop(mlx.mlx);
}
