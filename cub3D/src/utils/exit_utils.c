/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 10:39:41 by quill             #+#    #+#             */
/*   Updated: 2026/09/01 10:40:24 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_framework(t_framework *fw)
{
	if (!fw)
		return ;
	if (fw->content)
		ft_free_matrix(fw->content);
	if (fw->config)
		ft_free_matrix(fw->config);
	if (fw->map)
		ft_free_matrix(fw->map);
	if (fw->game.map.grid)
		ft_free_matrix(fw->game.map.grid);
	if (fw->game.images.no_path)
		free(fw->game.images.no_path);
	if (fw->game.images.so_path)
		free(fw->game.images.so_path);
	if (fw->game.images.we_path)
		free(fw->game.images.we_path);
	if (fw->game.images.ea_path)
		free(fw->game.images.ea_path);
	free(fw);
}

void	error_message(char *str, t_framework *fw)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	free_framework(fw);
	exit(EXIT_FAILURE);
}
