#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include "mlx.h"

#include <unistd.h>

int	loop(void *data)
{
	//t_loop_data d = *(t_loop_data*)data;
	(void)data;
	// exit(0);
	return 0;
}


void init(t_loop_data *mlx, t_main *m, int map)
{
	t_point *result = get_split_fdf(map, &m->size, &m->i_i, &m->j_j);
	mlx->result = result;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, W, H, "FDF");
	mlx->img.img = mlx_new_image(mlx->mlx, W, H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length,
								&mlx->img.endian);
	mlx_hook(mlx->mlx_win, 17, 0L, mlx_close, mlx);
	mlx_hook(mlx->mlx_win, 2, 1L<<0, esc_close, mlx);
	close(map);
}
void check()
{
	system("leaks fdf");
}

int main(int argnum, char **args)
{
		atexit(check);

	(void)(argnum);
	int map = open(args[1], O_RDONLY);
	t_main m = {0};
	t_loop_data mlx = {0};
	init(&mlx, &m, map);
	get_matrix(&mlx, m);
	m.i = 1;
	draw(mlx, m);	
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop_hook(mlx.mlx, loop, 0);
	mlx_loop(mlx.mlx);
	return 0;
}