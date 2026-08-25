#include "cub3d.h"

int	init_mlx(t_framework *fw)
{

	fw->mlx.mlx = mlx_init();
	if (!fw->mlx.mlx)
		return (1);
	fw->mlx.WIDTH = 1000;
    fw->mlx.HEIGHT = 500;
	fw->mlx.win = mlx_new_window(fw->mlx.mlx, fw->mlx.WIDTH, fw->mlx.HEIGHT, "cub3d");
	if (!fw->mlx.win)
		return (1);
	fw->mlx.frame.img = mlx_new_image(fw->mlx.mlx, fw->mlx.WIDTH, fw->mlx.HEIGHT);
	if (!fw->mlx.frame.img)
		return (1);


	fw->mlx.frame.addr = mlx_get_data_addr(
    fw->mlx.frame.img,
    &fw->mlx.frame.bpp,
    &fw->mlx.frame.line_length,
    &fw->mlx.frame.endian
	);
	if (!fw->mlx.frame.addr)
		return (1);
	return (0);
}

int	close_game(t_framework *fw)
{
    mlx_destroy_image(fw->mlx.mlx, fw->mlx.frame.img);
    mlx_destroy_window(fw->mlx.mlx, fw->mlx.win);
    mlx_destroy_display(fw->mlx.mlx);
    free(fw->mlx.mlx);
    exit(0);
    return (0);
}

int	key_press(int keycode, t_framework *fw)
{
    if (keycode == ESC_KEY)
        close_game(fw);
    return (0);
}

int run_mlx(t_framework *fw)
{
	render_frame(fw);
    mlx_hook(fw->mlx.win, 2, 1L << 0, key_press, fw);
    mlx_hook(fw->mlx.win, 17, 0, close_game, fw);
	mlx_loop(fw->mlx.mlx);
	return (0);
}