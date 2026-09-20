/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:20 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 06:05:36 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(t_color color)
{
    if (color.r < 0)
        color.r = 0;
    else if (color.r > 255)
        color.r = 255;
    if (color.g < 0)
        color.g = 0;
    else if (color.g > 255)
        color.g = 255;
    if (color.b < 0)
        color.b = 0;
    else if (color.b > 255)
        color.b = 255;
    return ((color.r << 16) | (color.g << 8) | color.b);
}

void	put_pixel(t_framework *fw, int x, int y, int color)
{
    char	*dst;
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    dst = fw->mlx.frame.addr + (y * fw->mlx.frame.line_length
            + x * (fw->mlx.frame.bpp / 8));
    *(unsigned int *)dst = color;
}

int	load_texture(t_framework *fw, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(fw->mlx.mlx, path, &img->width, &img->height);
    if (!img->img)
        return (1);
    img->addr = mlx_get_data_addr(
    img->img,
    &img->bpp,
    &img->line_length,
    &img->endian
	);
	if (!img->addr)
		return (1);
    return (0);
}