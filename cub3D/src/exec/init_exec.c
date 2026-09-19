/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:34:57 by albegar2          #+#    #+#             */
/*   Updated: 2026/09/19 18:44:25 by albegar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int init_exec(t_framework *fw)
{
    testing(fw);
	if (run_mlx(fw) == 1)
		return (1);
    //load textures
    //init render
    //register events
    //mlx_loop
    return (0);
}





