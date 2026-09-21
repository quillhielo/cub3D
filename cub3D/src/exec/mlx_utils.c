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

void	update_pos(t_framework *fw)
{
	if (!nowall(fw))
	{
		fw->game.player.x = fw->game.new_x;
		fw->game.player.y = fw->game.new_y;
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
	if (fw->mlx.keys.w)
	{
		fw->game.new_x = fw->game.player.x + dir_x * MOVE_SPEED;
		fw->game.new_y = fw->game.player.y + dir_y * MOVE_SPEED;
	}
	else if (fw->mlx.keys.s)
	{
		fw->game.new_x = fw->game.player.x - dir_x * MOVE_SPEED;
		fw->game.new_y = fw->game.player.y - dir_y * MOVE_SPEED;
	}
	else if (fw->mlx.keys.a)
	{
		fw->game.new_x = fw->game.player.x + dir_y * MOVE_SPEED;
		fw->game.new_y = fw->game.player.y - dir_x * MOVE_SPEED;
	}
	else if (fw->mlx.keys.d)
	{
		fw->game.new_x = fw->game.player.x - dir_y * MOVE_SPEED;
		fw->game.new_y = fw->game.player.y + dir_x * MOVE_SPEED;
	}
	update_pos(fw);
	update_rot(fw);
}
