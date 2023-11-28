#include <stdio.h>
#include "minirt.h"

int		get_color(double r_ratio, double g_ratio, double b_ratio);
void	draw_pixel(t_mlx *mlx, int width_idx, int height_idx, int color);

int main(void)
{
	t_mlx	mlx;

	mlx = new_mlx();
	int j = 0;
	while (j < HEIGHT) {
		int i = 0;
		while (i < WIDTH) {
			double r = (double)i / (WIDTH - 1);
            double g = (double)j / (HEIGHT - 1);
            double b = 0.25;
			draw_pixel(&mlx, i, j, get_color(r, g, b));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hooks(&mlx);
	mlx_loop(mlx.mlx);
}

int get_color(double r_ratio, double g_ratio, double b_ratio)
{
	int r = (int)(255.999 * r_ratio);
	int g = (int)(255.999 * g_ratio);
	int b = (int)(255.999 * b_ratio);
	return (r << 16 | g << 8 | b);
}

void	draw_pixel(t_mlx *mlx, int width_idx, int height_idx, int color)
{
	char	*dst;

	if (width_idx < 0 || width_idx > WIDTH || height_idx < 0 || height_idx > HEIGHT) {
		return ;
	}
	dst = mlx->addr + (height_idx * mlx->line_size + width_idx * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
