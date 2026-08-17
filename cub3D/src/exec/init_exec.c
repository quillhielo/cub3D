#include "cub3d.h"


int init_exec(int argc, char **argv, t_framework *fw)
{
	if (init_mlx(fw) == 1)
		return (1);
	if (run_mlx(fw) == 1)
		return (1);


    return (0);
}


int	init_mlx(t_framework *fw)
{

	fw->mlx.mlx = mlx_init();
	if (!fw->mlx.mlx)
		return (1);
	fw->mlx.win = mlx_new_window(fw->mlx.mlx, 1920, 1080, "cube3d");
	fw->mlx.frame = mlx_new_image(fw->mlx.mlx, 1920, 1080);
	if (!fw->mlx.frame)
		return (1);
	return (0);
}

int run_mlx(t_framework *fw)
{
	mlx_loop(fw->mlx.mlx);
	return (0);
}