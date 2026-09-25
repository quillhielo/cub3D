/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 11:08:23 by quill             #+#    #+#             */
/*   Updated: 2026/09/25 11:08:49 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player_loop(t_framework *fw, int i, int j, int *player)
{
	if (fw->map[i][j] == 'N' || fw->map[i][j] == 'S' || fw->map[i][j] == 'E'
		|| fw->map[i][j] == 'W')
	{
		if (*player > 0)
			error_message("Incorrect player number", fw);
		(*player)++;
		fw->game.player.x = j + 0.5;
		fw->game.player.y = i + 0.5;
		fw->game.player.angle = spawn_angle(fw->map[i][j]);
	}
}

void	check_player(t_framework *fw)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (fw->map[i])
	{
		j = 0;
		while (fw->map[i][j])
		{
			check_player_loop(fw, i, j, &player);
			j++;
		}
		i++;
	}
	if (player != 1)
		error_message("Incorrect player number", fw);
}
