/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quill <quill@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:33:21 by quill             #+#    #+#             */
/*   Updated: 2026/07/30 13:28:11 by quill            ###   ########.fr       */
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

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_images//alberto
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
}	t_images;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_images	images;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
}	t_game;

typedef struct s_mlx//alberto
{
	void	*mlx;
	void	*win;

	t_img	frame;
}	t_mlx;

typedef struct s_framework
{
	/* Temporal info*/
	char	**content;
	char	**config;
	char	**map;

	/* end data */
	t_game	game;

	/* graphic motor*/
	t_mlx	mlx;

}	t_framework;

//parsing
void    error_message(char *str);
void    load_file(int argc, char **argv, t_framework *fw);
int     is_map_line(char *line);
int     is_config_line(char *line);
int     find_map_start(t_framework *fw);
void    copy_map(t_framework *fw, int start_index);
void    copy_config(t_framework *fw, int end_index);
void    tidy_content(t_framework *fw);
void    get_content(int fd, t_framework *fw);
//exec
int 	init_exec(t_framework *fw);
int		init_mlx(t_framework *fw);
int		run_mlx(t_framework *fw);
void	put_pixel(t_img *image, int x, int y, int color);
void	render_frame(t_framework *fw);
int		close_game(t_framework *fw);
int		key_press(int keycode, t_framework *fw);
int		rgb_to_int(t_color color);

#endif