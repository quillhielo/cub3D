/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 09:47:53 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/20 10:11:23 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sidedist(t_raycast *rc)
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
}
