#include "../include/so_long.h"

int     key_exit(void)
{
    exit(0);
    return (0);
}

int     key_release(t_so_long *so_long, int keycode)
{
    if (keycode == W)
        so_long->player.WALK_X = 0;
    if (keycode == S)
        so_long->player.WALK_X = 0;
    if (keycode == A)
        so_long->player.WALK_Y = 0;
    if (keycode == D)
        so_long->player.WALK_Y = 0;
    if (keycode == ESC || keycode == 12)
        key_exit();
    return (0);
}

int     key_press(t_so_long *so_long, int keycode)
{
    if (keycode == W)
        so_long->player.WALK_X = 1;
    if (keycode == S)
        so_long->player.WALK_X = -1;
    if (keycode == A)
        so_long->player.WALK_Y = 1;
    if (keycode == D)
        so_long->player.WALK_Y = -1;
    return (0);
}
