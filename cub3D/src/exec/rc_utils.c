/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 08:04:54 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 08:12:03 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fisheye(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perpendicular = rc->sidedist_x - rc->deltadist_x;
	else
		rc->perpendicular = rc->sidedist_y - rc->deltadist_y;
}

double	get_wall_x(t_framework *fw, t_raycast *rc)
{
	double	wallhit_x;
	double	wallhit_y;
	double	wallx;

	wallhit_x = fw->game.player.x + rc->perpendicular * rc->raydir_x;
	wallhit_y = fw->game.player.y + rc->perpendicular * rc->raydir_y;
	if (rc->side == 0)
		wallx = wallhit_y - floor(wallhit_y);
	else
		wallx = wallhit_x - floor(wallhit_x);
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
