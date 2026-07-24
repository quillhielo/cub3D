/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:33:21 by quill             #+#    #+#             */
/*   Updated: 2026/07/24 18:51:18 by quill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h> //open
#include <unistd.h> //read, write, close
#include <stdlib.h> //malloc, free, exit
#include <stdio.h> //printf
#include <string.h> //strerror
#include <math.h> //sin, cos, tan, sqrt
#include "mlx.h" //mlx functions
#include "libft.h" //libft functions (permitted?)
#include "get_next_line.h"

# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define ESC_KEY 65307

typedef enum e_line_type
{
	EMPTY,
	CONFIG,
	MAP,
	INVALID
}	t_line_type;

typedef struct  s_floor
{
    int rgb_1;
    int rgb_2;
}t_floor;

typedef struct s_ceiling
{
    int rgb_1;
    int rgb_2;
}t_ceiling;

typedef struct s_images
{
    void    *wall_north;
    void    *wall_south;
    void    *wall_east;
    void    *wall_west;
    
}t_images;

typedef struct s_map
{
    
}t_map;

typedef struct s_player
{
    float   x;
    float   y;
    float   angle;
} t_player;

typedef struct s_game
{
    char        *content;
    t_map       *map;
    t_images    *images;
    t_floor      *floor;
    t_ceiling    *ceiling;
    t_player     *player;
    
}t_game;

typedef struct s_framewokr
{
    char **content;
    char **map;
    char **config;
    t_game *game;
} t_framework;

void    error_message(char *str);
void    parse_argv(int argc, char **argv, t_framework *fw);
int     is_map_line(char *line);
int     is_config_line(char *line);
int     find_map_start(t_framework *fw);
void    copy_map(t_framework *fw, int start_index);
void    copy_config(t_framework *fw, int end_index);
void    tidy_content(t_framework *fw);
void    get_content(int fd, t_framework *fw);

#endif