#include "cub3d.h"

char *debug_map[] = {
    "111111",
    "100001",
    "100001",
    "100001",
    "100001",
    "111111",
    NULL
};

void testing(t_framework *fw)
{
    fw->game.map.grid = debug_map;
    fw->game.map.width = 6;
    fw->game.map.height = 6;
    fw->game.player.x = 2.5;
    fw->game.player.y = 2.5;
    fw->game.player.angle = 0.0;
    fw->game.floor = (t_color){30, 30, 30};
    fw->game.ceiling = (t_color){100, 150, 220};
}
