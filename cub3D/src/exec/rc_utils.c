/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:04:54 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 10:09:33 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fisheye(t_raycast *rc, t_framework *fw)
{
	if (rc->side == 0)
		rc->perpendicular = rc->sidedist_x - rc->deltadist_x;
	else
		rc->perpendicular = rc->sidedist_y - rc->deltadist_y;
	rc->perpendicular *= cos(rc->ray_angle - fw->game.player.angle);
}

double	get_wall_x(t_framework *fw, t_raycast *rc)
{
	double	wallx;

	if (rc->side == 0)
		wallx = fw->game.player.y + rc->perpendicular * rc->raydir_y;
	else
		wallx = fw->game.player.x + rc->perpendicular * rc->raydir_x;
	wallx -= floor(wallx);
	return (wallx);
}

int	get_tex_x(double wallx, t_img *texture)
{
	int	texx;

	texx = (int)(wallx * texture->width);
	if (texx >= texture->width)
		texx = texture->width - 1;
	return (texx);
}

int	get_tex_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	cast_ray(t_framework *fw, int col)
{
	t_raycast	rc;

	init_raycasting(fw, col, &rc);
	update_dist(fw, &rc);
	if (!dda_loop(fw, &rc))
	{
		fisheye(&rc, fw);
		draw_column(fw, &rc, col);
	}
}
