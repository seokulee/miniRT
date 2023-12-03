#include "minilibx.h"

t_mlx	new_mlx(int width, int height)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, width, height, TITLE);
	mlx.img = mlx_new_image(mlx.mlx, width, height);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_size, &mlx.endian);
	return mlx;
}
