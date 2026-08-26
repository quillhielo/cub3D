/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 17:02:40 by quill             #+#    #+#             */
/*   Updated: 2026/08/25 17:43:43 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int    is_valid_map_char(char c)
{
    if (c == '0' || c == '1' || c == 'N' || c == 'S'
        || c == 'E' || c == 'W' || c == ' ')
        return (1);
    return (0);
}
void    check_map_chars(t_framework *fw)
{
    int i;
    int j;

    i = 0;
    while (fw->map[i])
    {
        j = 0;
        while(fw->map[i][j])
        {
            if(!is_valid_map_char(fw->map[i][j]))
                error_message("Invalid character in map")
            j++;
        }
        i++;
    }
}
void    check_player(t_framework *fw)
{
    int i;
    int j;
    int player;

    i = 0;
    player = 0;
    while (fw->map[i])
    {
        j = 0;
        while(fw->map[i][j])
        {
            if(fw->map[i][j] == 'N' || fw->map[i][j] == 'S'
                || fw->map[i][j] == 'E' || fw->map[i][j] == 'W')
            {
                if(player > 0)
                    error_message("Incorrect player number")
                player++;
                fw->game.player.x = j;
                fw->game.player.y = i;
                fw->game.player.orientation = fw->map[i][j];
            }
            j++;
        }
        i++;
    }
    if (player != 1)
	error_message("Incorrect player number");
}


