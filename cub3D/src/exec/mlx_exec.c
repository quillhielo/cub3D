/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:04 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/19 23:35:28 by albegar2         ###   ########.fr       */
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
    return (0);
}

int run_mlx(t_framework *fw)
{
	if (init_mlx(fw))
		return (1);
	render_frame(fw);
    mlx_hook(fw->mlx.win, 2, 1L << 0, key_press, fw);
    mlx_hook(fw->mlx.win, 17, 0, close_game, fw);
	mlx_loop(fw->mlx.mlx);
	return (0);
}

void	render_frame(t_framework *fw)
{
    int	x;
    int	y;

    y = 0;
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
}
