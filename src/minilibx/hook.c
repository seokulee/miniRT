#include "minilibx.h"

int	destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC) {
		destroy(mlx);
	}
	return 0;
}

void	mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 0, key_hook, mlx);
	mlx_hook(mlx->win, ON_DESTROY, 0, destroy, mlx);
}
