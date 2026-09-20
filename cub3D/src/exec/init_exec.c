/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:34:57 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 07:40:48 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int init_exec(t_framework *fw)
{
	if (run_mlx(fw) == 1)
		return (1);
	return (0);
}
int run_mlx(t_framework *fw)
{
	if (init_mlx(fw))
		return (1);
	if (load_all_textures(fw))
		return (1);
	mlx_loop_hook (fw->mlx.mlx, render_frame, fw);
    mlx_hook(fw->mlx.win, 2, 1L << 0, key_press, fw);
    mlx_hook(fw->mlx.win, 3, 1L << 1, key_release, fw);
    mlx_hook(fw->mlx.win, 17, 0, close_game, fw);
	mlx_loop(fw->mlx.mlx);
	return (0);
}

int	init_mlx(t_framework *fw)
{

	fw->mlx.mlx = mlx_init();
	if (!fw->mlx.mlx)
		return (1);
	fw->mlx.win = mlx_new_window(fw->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	fw->mlx.frame.img = mlx_new_image(fw->mlx.mlx, WIDTH, HEIGHT);
	if (!fw->mlx.win || !fw->mlx.frame.img)
		return (1);
	fw->mlx.frame.addr = mlx_get_data_addr(
    fw->mlx.frame.img,
    &fw->mlx.frame.bpp,
    &fw->mlx.frame.line_length,
    &fw->mlx.frame.endian
	);
	if (!fw->mlx.frame.addr)
		return (1);
	return (0);
}
int load_all_textures(t_framework *fw)
{
	if (load_texture(fw, fw->game.images.no_path, &fw->game.images.no_img))
		return (1);
	if (load_texture(fw, fw->game.images.so_path, &fw->game.images.so_img))
		return (1);
	if (load_texture(fw, fw->game.images.ea_path, &fw->game.images.ea_img))
		return (1);
	if (load_texture(fw, fw->game.images.we_path, &fw->game.images.we_img))
		return (1);
	return (0);
}


void	free_game(t_framework *fw)
{
	mlx_destroy_image(fw->mlx.mlx, fw->game.images.ea_img.img);
	mlx_destroy_image(fw->mlx.mlx, fw->game.images.no_img.img);
	mlx_destroy_image(fw->mlx.mlx, fw->game.images.so_img.img);
	mlx_destroy_image(fw->mlx.mlx, fw->game.images.we_img.img);
}