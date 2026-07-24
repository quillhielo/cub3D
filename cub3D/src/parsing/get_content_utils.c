/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:11:37 by quill             #+#    #+#             */
/*   Updated: 2026/07/24 18:46:00 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_config_line(char *line)
{
    if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
        || ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
        || ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
        return (1);
    return (0);
}
int is_map_line(char *line)
{
    if (ft_strlen(line) > 0 && !is_config_line(line))
        return (1);
    return (0);
}
int find_map_start(t_framework *fw)
{
    int i = 0;
    while (fw->content[i])
    {
        if (is_map_line(fw->content[i]))
            return (i);
        i++;
    }
    return (-1);
}
void copy_map(t_framework *fw, int start_index)
{
    int i = 0;
    while (fw->content[start_index + i])
    {
        if (is_map_line(fw->content[start_index + i]))
            i++;
        else
            error_message("Invalid line in map");
    }
    fw->map = ft_calloc(i + 1, sizeof(char *));
    if (!fw->map)
        error_message("Malloc failed");
    for (int j = 0; j < i; j++)
    {
        fw->map[j] = ft_strdup(fw->content[start_index + j]);
        if (!fw->map[j])
            error_message("Malloc failed");
    }
}
void copy_config(t_framework *fw, int end_index)
{
    int i ;
    int j ;
    
    i = 0;
    j = 0;
    while(fw->content[i] && i < end_index)
    {
        if (is_config_line(fw->content[i]))
            j++;
        i++;
    }
    fw->config = ft_calloc(j + 1, sizeof(char *));
    if (!fw->config)
        error_message("Malloc failed");
    j = 0;
    i = 0;
    while(fw->content[i] && i < end_index)
    {
        if (is_config_line(fw->content[i]))
        {
            fw->config[j] = ft_strdup(fw->content[i]);
            if (!fw->config[j])
                error_message("Malloc failed");
            j++;
        }
    }
}
