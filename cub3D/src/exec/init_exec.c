#include "cub3d.h"


int init_exec(t_framework *fw)
{
	if (init_mlx(fw) == 1 || run_mlx(fw) == 1)
		return (1);
    //load textures
    //init render
    //register events
    //mlx_loop
    return (0);
}

void	put_pixel(t_img *image, int x, int y, int color)
{
    char	*dst;

    if (x < 0 || x >= 1000 || y < 0 || y >= 500)
        return ;
    dst = image->addr + (y * image->line_length
            + x * (image->bpp / 8));
    *(unsigned int *)dst = color;
}

void	render_frame(t_framework *fw)
{
    int	x;
    int	y;

    y = 0;
    while (y < fw->mlx.HEIGHT)
    {
        x = 0;
        while (x < fw->mlx.WIDTH)
        {
            if (y < 540)
                put_pixel(&fw->mlx.frame, x, y, 0x355600);
            else
                put_pixel(&fw->mlx.frame, x, y, 0x193000);
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

