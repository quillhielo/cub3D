/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:35:14 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 10:16:50 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculations(t_framework *fw, t_raycast *rc, t_img *img)
{
	rc->line_height = (double)HEIGHT / rc->perpendicular;
	rc->draw_start = (HEIGHT / 2) - (rc->line_height / 2);
	rc->draw_end = (HEIGHT / 2) + (rc->line_height / 2);
	rc->wallx = get_wall_x(fw, rc);
	rc->step = (double)img->height / rc->line_height;
	rc->texpos = (rc->draw_start - HEIGHT / 2.0 + rc->line_height / 2.0)
		* rc->step;
	if (rc->draw_start < 0)
	{
		rc->texpos += -rc->draw_start * rc->step;
		rc->draw_start = 0;
	}
	if (rc->draw_end >= HEIGHT)
		rc->draw_end = HEIGHT;
}

void	draw_column(t_framework *fw, t_raycast *rc, int col)
{
	int		tex_y;
	int		tex_x;
	int		y;
	int		color;
	t_img	*img;

	img = get_wall_texture(fw, rc);
	calculations(fw, rc, img);
	tex_x = get_tex_x(rc->wallx, img);
	if ((rc->side == 0 && rc->raydir_x > 0) || (rc->side == 1
			&& rc->raydir_y < 0))
		tex_x = img->width - tex_x - 1;
	y = rc->draw_start;
	while (y < rc->draw_end)
	{
		tex_y = (int)rc->texpos;
		if (tex_y >= img->height)
			tex_y = img->height - 1;
		if (tex_y < 0)
			tex_y = 0;
		color = get_tex_pixel(img, tex_x, tex_y);
		put_pixel(fw, col, y, color);
		y++;
		rc->texpos += rc->step;
	}
}

void	init_raycasting(t_framework *fw, int col, t_raycast *rc)
{
	double	frac;

	frac = (double)col / WIDTH;
	rc->ray_angle = (fw->game.player.angle - FOV / 2) + (frac * FOV);
	rc->raydir_x = cos(rc->ray_angle);
	rc->raydir_y = sin(rc->ray_angle);
	if (rc->raydir_x == 0)
		rc->raydir_x = 0.00001;
	if (rc->raydir_y == 0)
		rc->raydir_y = 0.00001;
	rc->deltadist_x = fabs(1 / rc->raydir_x);
	rc->deltadist_y = fabs(1 / rc->raydir_y);
	rc->map_x = (int)fw->game.player.x;
	rc->map_y = (int)fw->game.player.y;
	return ;
}

void	update_dist(t_framework *fw, t_raycast *rc)
{
	if (rc->raydir_x >= 0)
		rc->step_x = +1;
	else
		rc->step_x = -1;
	if (rc->raydir_y >= 0)
		rc->step_y = +1;
	else
		rc->step_y = -1;
	if (rc->step_x == +1)
	{
		rc->sidedist_x = (((rc->map_x + 1) - fw->game.player.x)
				*rc->deltadist_x);
	}
	else
		rc->sidedist_x = ((fw->game.player.x - rc->map_x) * rc->deltadist_x);
	if (rc->step_y == +1)
		rc->sidedist_y = (((rc->map_y + 1) - fw->game.player.y)
				*rc->deltadist_y);
	else
		rc->sidedist_y = ((fw->game.player.y - rc->map_y) * rc->deltadist_y);
}

int	dda_loop(t_framework *fw, t_raycast *rc)
{
	int	wall;

	wall = 0;
	while (!wall)
	{
		check_sidedist(rc);
		if (rc->map_y < 0 || rc->map_y >= fw->game.map.height)
			return (1);
		if (rc->map_x < 0 || rc->map_x
			>= ft_strlen(fw->game.map.grid[rc->map_y]))
			return (1);
		if (fw->game.map.grid[rc->map_y][rc->map_x] == '1')
			wall = 1;
	}
	return (0);
}
