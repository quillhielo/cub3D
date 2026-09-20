/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:04 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 05:08:39 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_framework *fw)
{

	fw->mlx.mlx = mlx_init();
	if (!fw->mlx.mlx)
		return (1);
	fw->mlx.win = mlx_new_window(fw->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	fw->mlx.frame.img = mlx_new_image(fw->mlx.mlx, WIDTH, HEIGHT);
	if (!fw->mlx.win || !fw->mlx.frame.img)
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
    if (keycode == W_KEY)
        fw->mlx.keys.w = 1;
    if (keycode == A_KEY)
        fw->mlx.keys.a = 1;
    if (keycode == D_KEY)
        fw->mlx.keys.d = 1;
    if (keycode == S_KEY)
        fw->mlx.keys.s = 1;
    if (keycode == LEFT_ARROW_KEY)
        fw->mlx.keys.left = 1;
    if (keycode ==  RIGHT_ARROW_KEY)
        fw->mlx.keys.right = 1;
    return (0);
}

int key_release(int keycode, t_framework *fw)
{
    if (keycode == W_KEY)
        fw->mlx.keys.w = 0;
    if (keycode == A_KEY)
        fw->mlx.keys.a = 0;
    if (keycode == D_KEY)
        fw->mlx.keys.d = 0;
    if (keycode == S_KEY)
        fw->mlx.keys.s = 0;
    if (keycode == LEFT_ARROW_KEY)
        fw->mlx.keys.left = 0;
    if (keycode ==  RIGHT_ARROW_KEY)
        fw->mlx.keys.right = 0;
    return (0);
}

int run_mlx(t_framework *fw)
{
	if (init_mlx(fw))
		return (1);
	mlx_loop_hook (fw->mlx.mlx, render_frame, fw);
    mlx_hook(fw->mlx.win, 2, 1L << 0, key_press, fw);
    mlx_hook(fw->mlx.win, 3, 1L << 1, key_release, fw);
    mlx_hook(fw->mlx.win, 17, 0, close_game, fw);
	mlx_loop(fw->mlx.mlx);
	return (0);
}

int render_frame(t_framework *fw)
{
    int	x;
    int	y;

    y = 0;
    move_player(fw);
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                put_pixel(fw, x, y, rgb_to_int(fw->game.ceiling));
            else
                put_pixel(fw, x, y, rgb_to_int(fw->game.floor));
            x++;
        }
        y++;
    }
	x = 0;
	while (x <= WIDTH - 1)
	{
		cast_ray(fw, x);
		x++;
	}
    mlx_put_image_to_window(
        fw->mlx.mlx,
        fw->mlx.win,
        fw->mlx.frame.img,
        0,
        0
    );
    return (0);
}
void    move_player(t_framework *fw)
{
double	dirX;
	double	dirY;

	dirX = cos(fw->game.player.angle);
	dirY = sin(fw->game.player.angle);
	if (fw->mlx.keys.w)
	{
		fw->game.player.x += dirX * MOVE_SPEED;
		fw->game.player.y += dirY * MOVE_SPEED;
	}
	if (fw->mlx.keys.s)
	{
		fw->game.player.x -= dirX * MOVE_SPEED;
		fw->game.player.y -= dirY * MOVE_SPEED;
	}
	if (fw->mlx.keys.a)
	{
		fw->game.player.x += dirY * MOVE_SPEED;
		fw->game.player.y -= dirX * MOVE_SPEED;
	}
	if (fw->mlx.keys.d)
	{
		fw->game.player.x -= dirY * MOVE_SPEED;
		fw->game.player.y += dirX * MOVE_SPEED;
	}
	if (fw->mlx.keys.right)
		fw->game.player.angle += ROT_SPEED;
	if (fw->mlx.keys.left)
		fw->game.player.angle -= ROT_SPEED;  
}