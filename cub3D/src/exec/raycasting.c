/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:14 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 08:33:37 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_framework *fw, int col)
{
	t_raycast	rc;

	init_raycasting(fw, col, &rc);
	if (!dda_loop(fw, &rc))
	{
		fisheye(&rc);
		draw_column(fw, &rc, col);
	}
}

int	get_tex_pixel(t_img *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_column(t_framework *fw, t_raycast *rc, int col)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_y;
	int	tex_x;
	int y;
	int color;
	double wallx;
	double step;
	double texpos;
	t_img	*img;
	
	line_height = (double)HEIGHT / rc->perpendicular;
	draw_start = (HEIGHT / 2) - (line_height / 2);
	draw_end = (HEIGHT / 2) + (line_height / 2);
	img = get_wall_texture(fw, rc);
	step = (double)img->height / line_height;
	texpos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
	wallx = get_wall_x(fw, rc);
	tex_x = get_tex_x(wallx, img);
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)texpos;
		color = get_tex_pixel(img, tex_x, tex_y);
		put_pixel(fw, col, y, color);
		y++;
		texpos += step;
	}
}

void		init_raycasting(t_framework *fw, int col, t_raycast *rc)
{
	double	rayAngle;
	double	frac;
	
	frac = (double)col / WIDTH;
	rayAngle = (fw->game.player.angle - FOV / 2) + (frac * FOV); 
	rc->raydir_x = cos(rayAngle);
	rc->raydir_y = sin(rayAngle);
	if (rc->raydir_x == 0)
		rc->raydir_x = 0.00001;
	if (rc->raydir_y == 0)
		rc->raydir_y = 0.00001;
	rc->deltadist_x = fabs(1 / rc->raydir_x);
	rc->deltadist_y = fabs(1 / rc->raydir_y);
	rc->map_x = (int)fw->game.player.x;
	rc->map_y = (int)fw->game.player.y;
	if (rc->raydir_x >= 0)
		rc->step_x = +1;
	else
		rc->step_x = -1;
	if (rc->raydir_y >= 0)
		rc->step_y = +1;
	else
		rc->step_y = -1;
	if (rc->step_x == +1)
		rc->sidedist_x = (((rc->map_x + 1) - fw->game.player.x) *rc->deltadist_x);
	else
		rc->sidedist_x = ((fw->game.player.x - rc->map_x) * rc->deltadist_x);
	if (rc->step_y == +1)
		rc->sidedist_y = (((rc->map_y + 1) - fw->game.player.y) *rc->deltadist_y);
	else
		rc->sidedist_y = ((fw->game.player.y - rc->map_y) * rc->deltadist_y);
	return;
}

int	dda_loop(t_framework *fw, t_raycast *rc)
{
	int wall;

	wall = 0;
	while (!wall)
	{
		if (rc->sidedist_x > rc->sidedist_y)
		{
			rc->sidedist_y = rc->deltadist_y + rc->sidedist_y;
			rc->side = 1;
			if (rc->step_y == 1)
				rc->map_y++;
			else
				rc->map_y--;
		}
		else
		{
			rc->sidedist_x = rc->deltadist_x + rc->sidedist_x;
			rc->side = 0;
			if (rc->step_x == 1)
				rc->map_x++;
			else
				rc->map_x--;
		}
		if (rc->map_y < 0 || rc->map_y >= fw->game.map.height)
			return (1);
		if (rc->map_x < 0 || rc->map_x >= ft_strlen(fw->game.map.grid[rc->map_y]))
			return (1);	
		if (fw->game.map.grid[rc->map_y][rc->map_x] == '1')
			wall = 1;
	}
	return (0);
}
