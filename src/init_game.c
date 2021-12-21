#include "../include/so_long.h"

t_so_long        *init_game(char *filename)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)malloc(sizeof(t_so_long));
	if (so_long == 0)
		so_long_destroy(so_long, "init_game(): MALLOC FAILURE!!\n");
	so_long->game = 0;
	so_long->mlx_ptr = 0;
	so_long->imag = 0;
	so_long->win_ptr = 0;
	so_long->player = 0;
	so_long->exit = 0;
	so_long->collectible = 0;
	so_long->wall = 0;
	so_long->ground = 0;
	start_game(so_long, filename);
	render(so_long);
	read_texture(so_long);
	return (so_long);
}
