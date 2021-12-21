#include "../include/so_long.h"

int     key_exit(t_so_long *so_long)
{
	so_long_destroy(so_long);
	exit(0);
	return (0);
}

int     key_release(t_so_long *so_long, int keycode)
{
	if (keycode == W)
		so_long->game->player_up = 0;
	if (keycode == S)
		so_long->game->player_down = 0;
	if (keycode == A)
		so_long->game->player_left = 0;
	if (keycode == D)
		so_long->game->player_right = 0;
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
	if (keycode == ESC || keycode == 12)
		key_exit(so_long);
	return (0);
}
