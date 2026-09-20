/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:14 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 04:41:18 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_framework *fw, int col)
{
	t_raycast rc;
	
	init_raycasting(fw, col, &rc);
	if (!dda_loop(fw, &rc))
	{
		fisheye(&rc);
		draw_column(fw, &rc, col);
	}
}

void	draw_column(t_framework *fw, t_raycast *rc, int col)
{
	int lineHeight;
	int	drawStart;
	int	drawEnd;
	int	y;

	lineHeight = (double)HEIGHT / rc->perpendicular;
	drawStart = (HEIGHT / 2) - (lineHeight / 2);
	drawEnd = (HEIGHT / 2) + (lineHeight / 2);
	y = drawStart;
	while (y < drawEnd)
	{
		put_pixel(fw, col, y, 0xFF0000);
		y++;
	}
}

void		init_raycasting(t_framework *fw, int col, t_raycast *rc)
{
	double	rayAngle;
	double	frac;
	
	frac = (double)col / WIDTH;
	rayAngle = (fw->game.player.angle - FOV / 2) + (frac * FOV); 
	rc->rayDirX = cos(rayAngle);
	rc->rayDirY = sin(rayAngle);
	if (rc->rayDirX == 0)
   		rc->rayDirX = 0.00001;
	if (rc->rayDirY == 0)
    	rc->rayDirY = 0.00001;
	rc->deltaDistX = fabs(1 / rc->rayDirX);
	rc->deltaDistY = fabs(1 / rc->rayDirY);
	rc->mapX = (int)fw->game.player.x;
	rc->mapY = (int)fw->game.player.y;
	if (rc->rayDirX >= 0)
		rc->stepX = +1;
	else
		rc->stepX = -1;
	if (rc->rayDirY >= 0)
		rc->stepY = +1;
	else
		rc->stepY = -1;
	if (rc->stepX == +1)
		rc->sideDistX = (((rc->mapX + 1) - fw->game.player.x) *rc->deltaDistX);
	else
		rc->sideDistX = ((fw->game.player.x - rc->mapX) * rc->deltaDistX);
	if (rc->stepY == +1)
		rc->sideDistY = (((rc->mapY + 1) - fw->game.player.y) *rc->deltaDistY);
	else
		rc->sideDistY = ((fw->game.player.y - rc->mapY) * rc->deltaDistY);
	return;
}

int	dda_loop(t_framework *fw, t_raycast *rc)
{
	int wall;

	wall = 0;
	while (!wall)
	{
		if (rc->sideDistX > rc->sideDistY)
		{
			rc->sideDistY = rc->deltaDistY + rc->sideDistY;
			rc->side = 1;
			if (rc->stepY == 1)
				rc->mapY++;
			else
				rc->mapY--;
		}
		else
		{
			rc->sideDistX = rc->deltaDistX + rc->sideDistX;
			rc->side = 0;
			if (rc->stepX == 1)
				rc->mapX++;
			else
				rc->mapX--;
		}
		if (rc->mapY < 0 || rc->mapY >= fw->game.map.height)
			return (1);
		if (rc->mapX < 0 || rc->mapX >= ft_strlen(fw->game.map.grid[rc->mapY]))
			return (1);	
		if (fw->game.map.grid[rc->mapY][rc->mapX] == '1')
			wall = 1;
	}
	return (0);
}

void	fisheye(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perpendicular = rc->sideDistX - rc->deltaDistX;
	else
		rc->perpendicular = rc->sideDistY - rc->deltaDistY;
}