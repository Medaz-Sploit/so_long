#include "../include/so_long.h"

void	start_game(t_so_long *so_long, char **argv)
{
	so_long->game = (t_game *)malloc(sizeof(t_game));
	if (so_long->game == 0)
	{
		printf("Error: MALLOC FAILURE!!\n");
		so_long_destroy(so_long);
	}
	so_long->map = 0;
	so_long->game->coll = 0;
	so_long->game->count_coll = 0;
	so_long->game->count_exit = 0;
	so_long->game->count_player = 0;
	so_long->game->player_move = 0;
	so_long->game->player_coll = 0;
	so_long->game->player_up = 0;
	so_long->game->player_down = 0;
	so_long->game->player_left = 0;
	so_long->game->player_right = 0;
	map_init(so_long, argv[1]);
}
