/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:02:40 by quill             #+#    #+#             */
/*   Updated: 2026/09/01 11:21:01 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ')
		return (1);
	return (0);
}

int	is_walkable(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	check_map_chars(t_framework *fw)
{
	int	i;
	int	j;

	i = 0;
	while (fw->map[i])
	{
		j = 0;
		while (fw->map[i][j])
		{
			if (!is_valid_map_char(fw->map[i][j]))
				error_message("Invalid character in map", fw);
			j++;
		}
		i++;
	}
}

void	check_neighbor(t_framework *fw, int i, int j)
{
	if (i < 0 || j < 0)
		error_message("Map is not closed", fw);
	if (!fw->map[i])
		error_message("Map is not closed", fw);
	if (j >= (int)ft_strlen(fw->map[i]))
		error_message("Map is not closed", fw);
	if (fw->map[i][j] == ' ')
		error_message("Map is not closed", fw);
}

void	check_cell(t_framework *fw, int i, int j)
{
	check_neighbor(fw, i - 1, j);
	check_neighbor(fw, i + 1, j);
	check_neighbor(fw, i, j - 1);
	check_neighbor(fw, i, j + 1);
}
