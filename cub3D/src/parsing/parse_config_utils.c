/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:18:08 by quill             #+#    #+#             */
/*   Updated: 2026/09/04 18:00:09 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*parse_texture_path(char *line, t_framework *fw)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (line[i] == ' ')
		i++;
	j = i;
	if (line[i] == '\0')
		error_message("Invalid texture path", fw);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			error_message("Invalid texture path", fw);
		i++;
	}
	if (i < 5 || ft_strncmp(line + i - 4, ".xpm", 4) != 0)
		error_message("Invalid texture path", fw);
	if (access(line + j, F_OK) != 0)
		error_message("Texture file does not exist", fw);
	path = ft_strdup(line + j);
	if (!path)
		error_message("Failed to allocate memory for texture path", fw);
	return (path);
}

int	parse_texture(t_framework *fw, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (fw->game.images.no_path)
			error_message("North texture already set", fw);
		fw->game.images.no_path = parse_texture_path(line + 3, fw);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (fw->game.images.so_path)
			error_message("South texture already set", fw);
		fw->game.images.so_path = parse_texture_path(line + 3, fw);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (fw->game.images.we_path)
			error_message("West texture already set", fw);
		fw->game.images.we_path = parse_texture_path(line + 3, fw);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (fw->game.images.ea_path)
			error_message("East texture already set", fw);
		fw->game.images.ea_path = parse_texture_path(line + 3, fw);
	}
	else
		return (1);
	return (0);
}

void	parse_color(t_color *color, char *line, t_framework *fw)
{
	int		i;
	char	**colors;

	i = 2;
	if (color->set)
		error_message("Color already set", fw);
	color->set = 1;
	while (line[i] == ' ')
		i++;
	colors = ft_split(line + i, ',');
	if (!colors)
		error_message("Split failed", fw);
	is_valid_colors(colors, fw);
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	ft_free_matrix(colors);
}

void	is_valid_colors(char **colors, t_framework *fw)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (colors[i])
	{
		j = 0;
		count = 0;
		while (colors[i][j] == ' ')
			j++;
		while (ft_isdigit(colors[i][j]))
		{
			count++;
			j++;
		}
		while (colors[i][j] == ' ')
			j++;
		if (colors[i][j] != '\0' || count == 0 || ft_atoi(colors[i]) < 0
			|| ft_atoi(colors[i]) > 255)
			error_message("Invalid color format", fw);
		i++;
	}
	if (i != 3)
		error_message("Invalid color format", fw);
}
