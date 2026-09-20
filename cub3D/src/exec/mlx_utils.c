/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:30:05 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 08:30:47 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_pos(t_framework *fw, double new_x, double new_y)
{
	if (!nowall(fw, new_x, new_y))
	{
		fw->game.player.x = new_x;
		fw->game.player.y = new_y;
	}
}

void	update_rot(t_framework *fw)
{
	if (fw->mlx.keys.right)
		fw->game.player.angle += ROT_SPEED;
	if (fw->mlx.keys.left)
		fw->game.player.angle -= ROT_SPEED;
}

void	move_player(t_framework *fw, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	if (fw->mlx.keys.w)
	{
		new_x = fw->game.player.x + dir_x * MOVE_SPEED;
		new_y = fw->game.player.y + dir_y * MOVE_SPEED;
	}
	else if (fw->mlx.keys.s)
	{
		new_x = fw->game.player.x - dir_x * MOVE_SPEED;
		new_y = fw->game.player.y - dir_y * MOVE_SPEED;
	}
	else if (fw->mlx.keys.a)
	{
		new_x = fw->game.player.x + dir_y * MOVE_SPEED;
		new_y = fw->game.player.y - dir_x * MOVE_SPEED;
	}
	else if (fw->mlx.keys.d)
	{
		new_x = fw->game.player.x - dir_y * MOVE_SPEED;
		new_y = fw->game.player.y + dir_x * MOVE_SPEED;
	}
	update_pos(fw, new_x, new_y);
	update_rot(fw);
}
