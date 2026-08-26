#include "cub3d.h"

static char	r0[] = "1111111111111111111111111";
static char	r1[] = "1000000000110000000000001";
static char	r2[] = "1011000001110000000000001";
static char	r3[] = "1001000000000000000000001";
static char	r4[] = "111111111011000001110000000000001";
static char	r5[] = "100000000011000001110111111111111";
static char	r6[] = "11110111111111011100000010001";
static char	r7[] = "11110111111111011101010010001";
static char	r8[] = "11000000110101011100000010001";
static char	r9[] = "10000000000000001100000010001";
static char	r10[] = "10000000000000001101010010001";
static char	r11[] = "11000001110101011111011110N0111";
static char	r12[] = "11110111 1110101 101111010001";
static char	r13[] = "11111111 1111111 111111111111";

char    *g_map[] = {
	r0, r1, r2, r3, r4, r5, r6, r7,
	r8, r9, r10, r11, r12, r13, NULL
};

void testing(t_framework *fw)
{
    fw->game.map.grid = g_map;
    fw->game.map.width = 6;
    fw->game.map.height = 6;
    fw->game.player.x = 2.5;
    fw->game.player.y = 2.5;
    fw->game.player.angle = 0.0;
    fw->game.floor = (t_color){30, 30, 30};
    fw->game.ceiling = (t_color){100, 150, 220};
}

int	rgb_to_int(t_color color)
{
    if (color.r < 0)
        color.r = 0;
    else if (color.r > 255)
        color.r = 255;
    if (color.g < 0)
        color.g = 0;
    else if (color.g > 255)
        color.g = 255;
    if (color.b < 0)
        color.b = 0;
    else if (color.b > 255)
        color.b = 255;
    return ((color.r << 16) | (color.g << 8) | color.b);
}

