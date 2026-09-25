/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 11:18:08 by quill             #+#    #+#             */
/*   Updated: 2026/09/25 11:50:21 by quill            ###   ########.fr       */
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

void	set_texture(t_framework *fw, char **slot, char *error_msg, char *line)
{
	if (*slot)
		error_message(error_msg, fw);
	*slot = parse_texture_path(line + 3, fw);
}

int	parse_texture(t_framework *fw, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		set_texture(fw, &fw->game.images.no_path, "North texture already set",
			line);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		set_texture(fw, &fw->game.images.so_path, "South texture already set",
			line);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		set_texture(fw, &fw->game.images.we_path, "West texture already set",
			line);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		set_texture(fw, &fw->game.images.ea_path, "East texture already set",
			line);
	}
	else
		return (1);
	return (0);
}
