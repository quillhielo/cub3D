#include "cub3d.h"


int init_exec(t_framework *fw)
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
	
	fw->mlx.win = mlx_new_window(fw->mlx.mlx, 1920, 1080, "cub3d");
	if (!fw->mlx.win)
		return (1);
	fw->mlx.frame.img = mlx_new_image(fw->mlx.mlx, 1920, 1080);
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

void	put_pixel(t_img *image, int x, int y, int color)
{
    char	*dst;

    if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
        return ;
    dst = image->addr + (y * image->line_length
            + x * (image->bpp / 8));
    *(unsigned int *)dst = color;
}

void	render_frame(t_framework *fw)
{
    int	x;
    int	y;

    y = 0;
    while (y < 1080)
    {
        x = 0;
        while (x < 1920)
        {
            if (y < 540)
                put_pixel(&fw->mlx.frame, x, y, 0x355600);
            else
                put_pixel(&fw->mlx.frame, x, y, 0x193000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(
        fw->mlx.mlx,
        fw->mlx.win,
        fw->mlx.frame.img,
        0,
        0
    );
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