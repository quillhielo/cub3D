/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:04 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 08:31:49 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (keycode == RIGHT_ARROW_KEY)
		fw->mlx.keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_framework *fw)
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
	if (keycode == RIGHT_ARROW_KEY)
		fw->mlx.keys.right = 0;
	return (0);
}

void	drawing_pixels(t_framework *fw, int x, int y)
{
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
}

int	render_frame(t_framework *fw)
{
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;

	dir_x = cos(fw->game.player.angle);
	dir_y = sin(fw->game.player.angle);
	y = 0;
	x = 0;
	move_player(fw, dir_x, dir_y);
	drawing_pixels(fw, x, y);
	while (x <= WIDTH - 1)
	{
		cast_ray(fw, x);
		x++;
	}
	mlx_put_image_to_window(fw->mlx.mlx, fw->mlx.win, fw->mlx.frame.img,
		0, 0);
	return (0);
}

t_img	*get_wall_texture(t_framework *fw, t_raycast *rc)
{
	if (rc->side == 0)
	{
		if (rc->raydir_x > 0)
			return (&fw->game.images.we_img);
		else if (rc->raydir_x < 0)
			return (&fw->game.images.ea_img);
	}
	else
	{
		if (rc->raydir_y > 0)
			return (&fw->game.images.so_img);
		else if (rc->raydir_y < 0)
			return (&fw->game.images.no_img);
	}
	return (NULL);
}
