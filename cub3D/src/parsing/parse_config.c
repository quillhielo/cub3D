/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:18:12 by quill             #+#    #+#             */
/*   Updated: 2026/09/01 11:25:32 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_config_complete(t_framework *fw)
{
	if (!fw->game.images.no_path || !fw->game.images.so_path
		|| !fw->game.images.we_path || !fw->game.images.ea_path
		|| !fw->game.floor.set || !fw->game.ceiling.set)
		error_message("Missing configuration information", fw);
}

void	parse_config(t_framework *fw)
{
	int	i;

	i = 0;
	while (fw->config[i])
	{
		if (ft_strncmp(fw->config[i], "F ", 2) == 0)
			parse_color(&fw->game.floor, fw->config[i], fw);
		else if (ft_strncmp(fw->config[i], "C ", 2) == 0)
			parse_color(&fw->game.ceiling, fw->config[i], fw);
		else if (parse_texture(fw, fw->config[i]) != 0)
			error_message("Invalid configuration line", fw);
		i++;
	}
	check_config_complete(fw);
}
