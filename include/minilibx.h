#ifndef MINILIBX_H
# define MINILIBX_H

# include <stdlib.h>
# include "mlx.h"

/* Window */
# define TITLE "miniRT"

/* Hooking event */
# define ON_KEYDOWN 2
# define ON_DESTROY 17

/* Key code */
# define ESC 53

typedef struct s_mlx
{
    void    *mlx;
	void    *win;

	/* image */
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}   t_mlx;

/* init.c */
t_mlx	new_mlx(int width, int height);

/* hook.c */
void	mlx_hooks(t_mlx *mlx);

#endif
