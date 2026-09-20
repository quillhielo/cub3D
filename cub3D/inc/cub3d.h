/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albegar2 <albegar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:33:21 by quill             #+#    #+#             */
/*   Updated: 2026/09/20 05:09:59 by albegar2         ###   ########.fr       */
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
# define D_KEY 	100
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define ESC_KEY 65307
# define FOV 	1.0471975512
# define PI		3.14159265359
# define WIDTH	3840
# define HEIGHT	2160
# define BLOCK	64
# define ROT_SPEED 0.05
# define MOVE_SPEED 0.05

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
	int	set;
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
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
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

typedef struct s_keys
{
	int	w;
	int	a;
	int s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_mlx//alberto
{
	void	*mlx;
	void	*win;
	
	t_img	frame;
	t_keys	keys;
}	t_mlx;

typedef struct s_raycast
{
	int			side;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	double		rayDirX;
	double		rayDirY;
	double		deltaDistX;
	double		deltaDistY;
	double		sideDistX;
	double		sideDistY;
	double		perpendicular;
}	t_raycast;

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
void	ft_free_matrix(char **matrix);
void    error_message(char *str, t_framework *fw);
void    load_file(int argc, char **argv, t_framework *fw);
int     is_map_line(char *line);
int     is_config_line(char *line);
int     find_map_start(t_framework *fw);
void    copy_map(t_framework *fw, int start_index);
void    copy_config(t_framework *fw, int end_index);
void	split_content(t_framework *fw);
void    get_content(int fd, t_framework *fw);
int    parse_texture(t_framework *fw, char *line);
char	*parse_texture_path(char *line, t_framework *fw);
void	parse_color(t_color *color, char *line, t_framework *fw);
void	is_valid_colors(char **colors, t_framework *fw);
void	check_config_complete(t_framework *fw);
void	parse_config(t_framework *fw);
void    parse_map(t_framework *fw);
void    check_map_chars(t_framework *fw);
void	check_map_closed(t_framework *fw);
void	check_player(t_framework *fw);
void	check_cell(t_framework *fw, int i, int j);
void	check_neighbor(t_framework *fw, int i, int j);
int		is_walkable(char c);
//exec
int 	init_exec(t_framework *fw);
int		init_mlx(t_framework *fw);
int		run_mlx(t_framework *fw);
void	put_pixel(t_framework *fw, int x, int y, int color);
int		render_frame(t_framework *fw);
int		close_game(t_framework *fw);
int		key_press(int keycode, t_framework *fw);
int 	key_release(int keycode, t_framework *fw);
int		rgb_to_int(t_color color);
void    move_player(t_framework *fw);
//RAYCASTING
void	render_raycasting(t_framework *fw);
void	fisheye(t_raycast *rc);
int		dda_loop(t_framework *fw, t_raycast *rc);
void	init_raycasting(t_framework *fw, int col, t_raycast *rc);
void	cast_ray(t_framework *fw, int col);
void	draw_column(t_framework *fw, t_raycast *rc, int col);
//TESTING FUNCTIONS (DELETE LATER)
void 	testing(t_framework *fw);

#endif