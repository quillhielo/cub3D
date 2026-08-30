/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:30:33 by quill             #+#    #+#             */
/*   Updated: 2026/08/30 13:13:58 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    get_map_measures(t_framework *fw, char **map)
{
    int i;
    int j;
    int mj;

    i = 0;
    mj = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
            j++;
        if (j > mj)
            mj = j;
        i++;
    }
    fw->game.map.width = mj;
    fw->game.map.height = i;
}

void    fill_map_struct(t_framework *fw)
{
    get_map_measures(fw, fw->map);
    fw->game.map.grid = fw->map;
    fw->map = NULL;
}

void    parse_map(t_framework *fw)
{
    check_map_chars(fw);
    check_map_closed(fw);
    check_player(fw);
    fill_map_struct(fw);
}
