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



void	render_frame(t_framework *fw)
{
    int	x;
    int	y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (y < HEIGHT / 2)
                put_pixel(fw, x, y, rgb_to_int(fw->game.ceiling));
            else
                put_pixel(fw, x, y, rgb_to_int(fw->game.floor));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(
        fw->mlx.mlx,
        fw->mlx.win,
        fw->mlx.frame.img,
        0,
        0
    );
}

