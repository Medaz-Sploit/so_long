#include "../include/so_long.h"

t_so_long        *init_game(char *lin)
{
	t_so_long	*so_long;

	so_long = (t_so_long *)malloc(sizeof(t_so_long));
	if (so_long == 0)
		so_long_destroy(so_long, "init_game(): MALLOC FAILURE!!\n");
	so_long->game = 0;
	so_long->mlx_ptr = 0;
	so_long->imag = 0;
	so_long->win_ptr = 0;
	so_long->
	//player_position(so_long);
	//texture(so_long);
	//sprite(so_long);
	start_game(so_long, line)
	render(so_long);
	texture(so_long);
	return (so_long)
}
