/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:33 by quill             #+#    #+#             */
/*   Updated: 2026/09/01 11:16:14 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_closed(t_framework *fw)
{
	int	i;
	int	j;

	i = 0;
	while (fw->map[i])
	{
		j = 0;
		while (fw->map[i][j])
		{
			if (is_walkable(fw->map[i][j]))
				check_cell(fw, i, j);
			j++;
		}
		i++;
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
			if (fw->map[i][j] == 'N' || fw->map[i][j] == 'S'
				|| fw->map[i][j] == 'E' || fw->map[i][j] == 'W')
			{
				if (player > 0)
					error_message("Incorrect player number", fw);
				player++;
				fw->game.player.x = j;
				fw->game.player.y = i;
				fw->game.player.orientation = fw->map[i][j];
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		error_message("Incorrect player number", fw);
}

void	get_map_measures(t_framework *fw, char **map)
{
	int	i;
	int	j;
	int	mj;

	i = 0;
	mj = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > mj)
			mj = j;
		i++;
	}
	fw->game.map.width = mj;
	fw->game.map.height = i;
}

void	fill_map_struct(t_framework *fw)
{
	get_map_measures(fw, fw->map);
	fw->game.map.grid = fw->map;
	fw->map = NULL;
}

void	parse_map(t_framework *fw)
{
	check_map_chars(fw);
	check_map_closed(fw);
	check_player(fw);
	fill_map_struct(fw);
}
