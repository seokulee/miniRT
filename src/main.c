#include <stdio.h>
#include "minirt.h"

void	draw_pixel(t_mlx *mlx, t_pixel pixel, int color);

int main(void)
{
	t_view	view;
	t_mlx	mlx;
	t_object sphere;

	view = new_view(WIDTH, HEIGHT, new_vector(0, 0, 0)); // camera position : (0, 0, 0)
	sphere = new_sphere(new_vector(0, 0, -5), 2);

	// rendering
	mlx = new_mlx();
	int j = 0;
	while (j < HEIGHT) {
		int i = 0;
		while (i < WIDTH) {
			t_pixel pixel = new_pixel(i, j);
			t_ray ray = ray_from_camera(pixel, view);
			draw_pixel(&mlx, pixel, convert_color(get_color(&ray, sphere)));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hooks(&mlx);
	mlx_loop(mlx.mlx);
}

void	draw_pixel(t_mlx *mlx, t_pixel pixel, int color)
{
	char	*dst;

	if (pixel.x < 0 || pixel.x > WIDTH || pixel.y < 0 || pixel.y > HEIGHT) {
		return ;
	}
	dst = mlx->addr + (pixel.y * mlx->line_size + pixel.x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
