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

	t_color white = new_color(1, 1, 1);
	t_color sky_blue = new_color(0.5, 0.7, 1);
	double ratio = 0.5 * (ray->dir.y + 1.0);
	return new_color(
		white.r * (1.0 - ratio) + sky_blue.r * ratio,
		white.g * (1.0 - ratio) + sky_blue.g * ratio,
		white.b * (1.0 - ratio) + sky_blue.b * ratio);
}

void rendering(t_view *view, t_world *world)
{
	t_mlx mlx;

	mlx = new_mlx(view->w_width, view->w_height);
	int j = 0;
	while (j < view->w_height)
	{
		int i = 0;
		while (i < view->w_width)
		{
			t_pixel pixel = new_pixel(i, j);
			t_ray ray = new_ray(view->camera, dir_to_pixel(pixel, view));
			color_pixel(&mlx, pixel, ray_tracing(&ray, world));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hooks(&mlx);
	mlx_loop(mlx.mlx);
}
