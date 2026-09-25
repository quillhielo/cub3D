/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:27:04 by quill             #+#    #+#             */
/*   Updated: 2026/09/24 11:27:10 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	is_valid_colors_loop(t_framework *fw, char **colors, char *color)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (color[j] == ' ')
		j++;
	while (ft_isdigit(color[j]))
	{
		count++;
		j++;
	}
	while (color[j] == ' ')
		j++;
	if (color[j] != '\0' || count == 0 || ft_atoi(color) < 0
		|| ft_atoi(color) > 255)
	{
		ft_free_matrix(colors);
		error_message("Invalid color format", fw);
	}
}

void	is_valid_colors(char **colors, t_framework *fw)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		is_valid_colors_loop(fw, colors, colors[i]);
		i++;
	}
	if (i != 3)
	{
		ft_free_matrix(colors);
		error_message("Invalid color format", fw);
	}
}
